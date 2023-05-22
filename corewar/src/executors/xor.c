/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** xor
*/

#include <sys/types.h>

#include "corewar/arguments.h"
#include "corewar/corewar.h"

int exec_xor(program_t *p, char *memory, int *pc)
{
    u_char *arg_types = (u_char[4]){0};
    int reg = -1;
    int arg1 = 0;
    int arg2 = 0;

    get_arg_types(memory, ++*pc, arg_types);
    *pc += 1;
    get_arg(&arg1, memory, pc, arg_types[0]);
    get_arg(&arg2, memory, pc, arg_types[1]);
    get_arg(&reg, memory, pc, arg_types[2]);
    if (reg == 0)
        return 0;
    p->registers[reg - 1] = arg1 ^ arg2;
    p->carry = 1;
    return 0;
}
