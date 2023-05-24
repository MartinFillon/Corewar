/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** add
*/

#include <stdio.h>
#include <sys/types.h>
#include "corewar/arguments.h"
#include "corewar/corewar.h"

int exec_add(vm_t *vm, program_t *p)
{
    u_char *arg_types = (u_char[4]){0};
    int reg1 = 0;
    int reg2 = 0;
    int reg3 = 0;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg_types(vm->arena, p->pc, arg_types);
    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&reg1, vm->arena, &p->pc, T_REG);
    get_arg(&reg2, vm->arena, &p->pc, T_REG);
    get_arg(&reg3, vm->arena, &p->pc, T_REG);

    p->registers[reg3 - 1] = p->registers[reg1 - 1] + p->registers[reg2 - 1];
    p->carry = p->registers[reg3 - 1] == 0;
    return 0;
}
