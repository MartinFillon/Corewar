/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** and
*/

#include <stdio.h>
#include <sys/types.h>

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/op.h"

int exec_and(vm_t *vm, program_t *p)
{
    u_char *arg_types = (u_char[4]){0};
    int reg = -1;
    int arg1 = 0;
    int arg2 = 0;
    int st = p->pc;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg_types(vm->arena, p->pc, arg_types);
    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&arg1, vm->arena, &p->pc, arg_types[0]);
    get_arg(&arg2, vm->arena, &p->pc, arg_types[1]);
    get_arg(&reg, vm->arena, &p->pc, arg_types[2]);
    if (arg_types[0] == 0b11)
        arg1 = vm->arena[(st + arg1 % IDX_MOD) % MEM_SIZE];
    if (arg_types[1] == 0b11)
        arg2 = vm->arena[(st + arg2 % IDX_MOD) % MEM_SIZE];
    if (arg_types[0] == T_REG)
        arg1 = p->registers[arg1 - 1];
    if (arg_types[1] == T_REG)
        arg2 = p->registers[arg2 - 1];
    p->registers[reg - 1] = arg1 & arg2;
    p->carry = p->registers[reg - 1] == 0;
    return 0;
}
