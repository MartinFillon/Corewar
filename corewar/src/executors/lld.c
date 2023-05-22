/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** lld
*/

#include <sys/types.h>
#include "corewar/corewar.h"

int exec_lld(program_t *p, char *memory, int *pc)
{
    int arg = 0;
    int reg = 0;
    u_char *arg_types = (u_char[4]){0};

    get_arg_types(memory, ++*pc, arg_types);
    *pc += 1;
    get_arg(&arg, memory, pc, arg_types[0]);
    get_arg(&reg, memory, pc, arg_types[1]);
    if (reg == 0)
        return 0;
    p->registers[reg - 1] = arg;
    p->carry = 1;
    return 0;
}
