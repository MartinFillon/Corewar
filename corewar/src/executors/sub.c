/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sub
*/

#include "corewar/arguments.h"

int exec_sub(vm_t *vm, program_t *p)
{
    int reg1 = vm->arena[p->pc + 2];
    int reg2 = vm->arena[p->pc + 3];
    int reg3 = vm->arena[p->pc + 4];

    p->registers[reg3 - 1] = p->registers[reg1 - 1] - p->registers[reg2 - 1];
    p->pc = (p->pc + 5) % MEM_SIZE;
    p->carry = p->registers[reg3 - 1] == 0;
    return 0;
}
