/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** add
*/

#include "corewar/arguments.h"

int exec_add(vm_t *vm, program_t *p)
{
    int reg1 = vm->arena[(p->pc + 2) % MEM_SIZE];
    int reg2 = vm->arena[(p->pc + 3) % MEM_SIZE];
    int reg3 = vm->arena[(p->pc + 4) % MEM_SIZE];

    p->registers[reg3 - 1] = p->registers[reg1 - 1] + p->registers[reg2 - 1];
    p->pc = (p->pc + 5) % MEM_SIZE;
    return 0;
}
