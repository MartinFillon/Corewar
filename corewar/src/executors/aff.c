/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** aff
*/

#include <sys/types.h>

#include "my_stdio.h"
#include "corewar/corewar.h"

int exec_aff(program_t *p, char *memory, int *pc)
{
    (void) p;
    u_char *arg_types = (u_char[4]){0};
    int reg = 0;

    get_arg_types(memory, ++*pc, arg_types);
    *pc += 1;
    reg = memory[*pc] % 256;
    my_dprintf(1, "%c", reg);
    return 0;
}
