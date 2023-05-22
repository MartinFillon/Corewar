/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sti
*/

#include "corewar/corewar.h"

int exec_sti(program_t *p, char *memory, int *pc)
{
    u_char *arg_types = (u_char[4]){0};
    int reg = -1;
    int arg1 = 0;
    int arg2 = 0;

    get_arg_types(memory, ++*pc, arg_types);
    *pc += 1;
    get_arg(&reg, memory, pc, arg_types[0]);
    if (reg == 0)
        return 0;
    get_arg(&arg1, memory, pc, arg_types[1]);
    get_arg(&arg2, memory, pc, arg_types[2]);

    memory[(*pc + (arg1 + arg2) % IDX_MOD) % MEM_SIZE] =
        p->registers[reg - 1] >> 24;
    return 0;
}
