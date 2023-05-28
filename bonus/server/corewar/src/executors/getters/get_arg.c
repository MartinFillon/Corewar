/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_arg
*/

#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"
#include "my_stdlib.h"

static get_arg_t GETTERS[] = {NULL, &get_reg, &get_dir, &get_ind};


arg_types_t get_reg(u_char *memory, int *pc)
{
    arg_types_t arg = {0};

    arg.reg = memory[*pc % MEM_SIZE];
    inc_pc(pc, 1);
    if (arg.reg < 1 || arg.reg > REG_NUMBER)
        arg.reg = CHAR_MAX;
    return arg;
}

void get_ind_value(
    arg_types_t *indirect, u_char *memory, int start, bool _idx_mod
)
{
    if (_idx_mod)
        indirect->ind.value =
            memory[(start + (indirect->ind.ind % IDX_MOD)) % MEM_SIZE];
    else
        indirect->ind.value = memory[(start + indirect->ind.ind) % MEM_SIZE];
}

int get_value(argument_t *args, program_t *p, ind_state_t *ind_state)
{
    if (args->arg_type == T_REG &&
        (args->data.reg >= 1 && args->data.reg <= REG_NUMBER)) {
        return p->registers[args->data.reg - 1];
    }
    if (args->arg_type == T_DIR)
        return args->data.dir;
    get_ind_value(
        &args->data, ind_state->memory, ind_state->start, ind_state->_idx_mod
    );
    return args->data.ind.value;
}

void get_arg(argument_t *arg, u_char *memory, int *pc)
{
    if (arg->arg_type == 0)
        return;
    if (arg->is_index == false)
        arg->data = GETTERS[arg->arg_type](memory, pc);
    else if (arg->is_index == true && arg->arg_type != T_REG)
        arg->data = get_ind(memory, pc);
    else
        arg->data = get_reg(memory, pc);
}
