/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** add
*/

#include "corewar/arguments.h"

int exec_add(program_t *p, char *memory, int *pc)
{
    int reg1 = memory[*pc + 2];
    int reg2 = memory[*pc + 3];
    int reg3 = memory[*pc + 4];

    p->registers[reg3 - 1] = p->registers[reg1 - 1] + p->registers[reg2 - 1];
    *pc += 5;
    return 0;
}
