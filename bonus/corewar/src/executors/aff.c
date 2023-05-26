/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** aff
*/

#include <sys/types.h>

#include "corewar/corewar.h"
#include "my_stdio.h"

int exec_aff(vm_t *vm, program_t *p)
{
    u_char *arg_types = (u_char[4]){0};
    int reg = 0;

    p->pc = (p->pc + 1) % MEM_SIZE;
    get_arg_types(vm->arena, p->pc, arg_types);
    p->pc = (p->pc + 1) % MEM_SIZE;
    reg = vm->arena[p->pc] % 256;
    my_dprintf(1, "%c", reg);
    return 0;
}
