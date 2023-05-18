/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ld
*/

#include <stddef.h>
#include "my_stdio.h"

#include "corewar/corewar.h"

int exec_ld(program_t UNUSED *p, char *memory, int *pc)
{
    u_char *arg_types =(u_char[4]){0};
    int reg = -1;
    int arg1 = 0;

    get_arg_types(memory, ++*pc, arg_types);
    if (arg_types[0] == T_DIR)
        arg1 = get_direct(memory, (*pc)++);
    else if (arg_types[0] == T_IND)
        arg1 = get_indirect(memory, (*pc)++);
    else
        return 0;
    reg = memory[(*pc)++];
    p->registers[reg - 1] = arg1;
    return 0;
}
