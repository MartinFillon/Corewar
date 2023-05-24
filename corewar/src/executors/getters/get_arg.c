/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_arg
*/

#include <complex.h>
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int convert_index(u_char type, program_t *p, int st, vm_t *vm)
{
    arg_types_t arg = {0};
    get_arg(&arg, vm->arena, &p->pc, (type == T_REG) ? T_REG : 0b11);
    if (type == T_REG) {
        if (arg.reg < 1 || arg.reg > REG_NUMBER)
            return 0;
        return p->registers[arg.reg - 1];
    }
    if (type == T_DIR)
        return arg.dir;
    if (type == 0b11)
        return vm->arena[(st + arg.ind % IDX_MOD) % MEM_SIZE];
    return 0;
}

int convert_index_long(u_char type, program_t *p, int st, vm_t *vm)
{
    arg_types_t arg = {0};
    get_arg(&arg, vm->arena, &p->pc, (type == T_REG) ? T_REG : 0b11);
    if (type == T_REG) {
        if (arg.reg < 1 || arg.reg > REG_NUMBER)
            return 0;
        return p->registers[arg.reg - 1];
    }
    if (type == T_DIR)
        return arg.dir;
    if (type == 0b11)
        return vm->arena[(st + arg.ind) % MEM_SIZE];
    return 0;
}

int get_arg(arg_types_t *arg, u_char *memory, int *pc, u_char arg_type)
{
    if (arg_type == 0b10) {
        *arg = get_direct(memory, *pc);
        inc_pc(pc, DIR_SIZE);
        return 1;
    }
    if (arg_type == 0b11) {
        *arg = get_indirect(memory, *pc);
        inc_pc(pc, IND_SIZE);
        return 1;
    }
    if (arg_type == 0b01) {
        (*arg).reg = memory[*pc] % (REG_NUMBER + 1);
        inc_pc(pc, 1);
        return 1;
    }
    return 0;
}
