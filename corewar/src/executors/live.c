/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** live
*/

#include "my_stdio.h"

#include "corewar/arguments.h"

int exec_live(program_t *p, char *memory, int *memory_index)
{
    char arg = memory[*memory_index + 1];
    if (arg < 1)
        return 1;
    int reg = p->registers[arg - 1];

    my_printf("The player %d(%s) is alive.\n", reg, p->header.prog_name);
    return 0;
}
