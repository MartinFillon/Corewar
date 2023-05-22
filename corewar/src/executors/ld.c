/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ld
*/

#include <stddef.h>
#include "my_stdio.h"

#include "corewar/corewar.h"

int exec_ld(vm_t *vm, program_t *p)
{
    u_char *arg_types = (u_char[4]){0};
    int reg = -1;
    int arg1 = 0;

    get_arg_types(vm->arena, p->pc + 1, arg_types);
    if (arg_types[0] == T_DIR)
        arg1 = get_direct(vm->arena, p->pc + 2);
    else if (arg_types[0] == T_IND)
        arg1 = get_indirect(vm->arena, p->pc + 2, p->pc);
    else
        return 0;
    reg = vm->arena[p->pc + 3];
    p->registers[reg - 1] = arg1;
    p->pc = (p->pc + 4) % MEM_SIZE;
    return 0;
}
