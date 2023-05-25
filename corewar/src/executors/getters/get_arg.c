/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_arg
*/

#include <stdbool.h>
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"
#include "my_stdlib.h"

static get_arg_t GETTERS[] = {NULL, &get_reg, &get_dir, &get_ind};

arg_types_t get_dir(u_char *memory, int *pc)
{
    arg_types_t arg = {0};

    arg.dir = 0;
    my_memcpy(&arg.dir, memory + *pc, DIR_SIZE);
    arg.dir = swap_endian(arg.dir);
    inc_pc(pc, DIR_SIZE);
    return arg;
}

arg_types_t get_ind(u_char *memory, int *pc)
{
    arg_types_t arg = {0};

    arg.ind.ind = 0;
    my_memcpy(&arg.ind.ind, memory + *pc, IND_SIZE);
    inc_pc(pc, IND_SIZE);
    return arg;
}

arg_types_t get_reg(u_char *memory, int *pc)
{
    arg_types_t arg = {0};

    arg.reg = memory[*pc];
    inc_pc(pc, 1);
    if (arg.reg < 1 || arg.reg > REG_NUMBER)
        arg.reg = -1;
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
    if (args->arg_type == T_REG)
        return p->registers[args->data.reg - 1];
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
    if (arg->is_index == true && arg->arg_type != T_REG)
        arg->data = get_ind(memory, pc);
    if (arg->arg_type == T_DIR && arg->is_index) {
        arg->data.ind.ind = swap_endian_short(arg->data.ind.ind);
    }
    if (arg->is_index == true && arg->arg_type == T_REG)
        get_reg(memory, pc);
}
