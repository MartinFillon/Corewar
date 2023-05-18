/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** live
*/

#include "my_stdio.h"

#include "corewar/corewar.h"
#include "corewar/arguments.h"

int exec_live(program_t *p, char *memory, int *pc)
{
    int arg = get_direct(memory, (*pc)++);

    my_printf("The player %d(%s) is alive.\n", arg, p->header.prog_name);
    return 0;
}
