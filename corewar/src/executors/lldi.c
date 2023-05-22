/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** exec_lldi
*/

#include "corewar/instructions.h"

int exec_lldi(program_t *p, char *memory, int *pc)
{
    int arg1 = 0;
    int arg2 = 0;
    int reg = 0;
    int st = *pc;
    u_char *arg_types = (u_char[4]){0};

    get_arg_types(memory, ++*pc, arg_types);
    *pc += 1;
    get_arg(&arg1, memory, pc, arg_types[0]);
    get_arg(&arg2, memory, pc, arg_types[1]);
    get_arg(&reg, memory, pc, arg_types[2]);
    if (reg == 0)
        return 0;
    p->registers[reg - 1] = get_direct(memory, st + (arg1 + arg2));
    return 0;
}