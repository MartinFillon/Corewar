/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** st
*/

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int exec_st(vm_t *vm, program_t *p)
{
    u_char *arg_types = (u_char[4]){0};
    arg_types_t reg = {0};
    arg_types_t arg1 = {0};
    int st = p->pc;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg_types(vm->arena, p->pc, arg_types);
    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&reg, vm->arena, &p->pc, arg_types[0]);
    get_arg(&arg1, vm->arena, &p->pc, arg_types[1]);
    if (reg.reg < 1 || reg.reg > REG_NUMBER)
        return 0;

    p->registers[reg.reg - 1] = (arg_types[1] == T_REG)
        ? p->registers[arg1.reg - 1]
        : vm->arena[(st + arg1.ind % IDX_MOD) % MEM_SIZE];
    return 0;
}
