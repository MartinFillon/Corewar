/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** aff
*/

#include "my_stdio.h"

#include "corewar/corewar.h"
#include "corewar/instructions.h"

int exec_aff(vm_t *vm, program_t *p)
{
    arg_types_t reg = {0};

    p->pc = (p->pc + 2) % MEM_SIZE;
    get_arg(&reg, vm->arena, &p->pc, T_REG);
    my_dprintf(1, "%c", reg.reg);
    return 0;
}
