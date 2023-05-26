/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** zjmp
*/

#include <stdio.h>

#include "corewar/corewar.h"
#include "corewar/op.h"

int exec_zjmp(vm_t *vm, program_t *p)
{
    int arg = 0;
    int address = p->pc;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg(&arg, vm->arena, &p->pc, 0b11);
    if (p->carry == 1)
        p->pc = (address + (arg % IDX_MOD)) % MEM_SIZE;
    return 0;
}
