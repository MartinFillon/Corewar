/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** or
*/

#include <sys/types.h>

#include "corewar/arguments.h"
#include "corewar/corewar.h"

int exec_or(vm_t *vm, program_t *p)
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
    interpret_binary(&arg1, arg_types[0], vm, st);
    interpret_binary(&arg2,arg_types[1], vm, st);
    if (arg_types[0] == T_REG)
        arg1 = p->registers[arg1 - 1];
    if (arg_types[1] == T_REG)
        arg2 = p->registers[arg2 - 1];
    if (reg > 0 && reg < REG_NUMBER)
        p->carry = (p->registers[reg - 1] = arg1 | arg2) == 0;
    return 0;
}
