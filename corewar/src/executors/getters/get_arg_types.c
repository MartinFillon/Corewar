/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_arg_types
*/

#include "corewar/corewar.h"

void get_arg_types(u_char *memory, int *pc, u_char *arg_types)
{
    inc_pc(pc, 1);

    u_char coding_byte = memory[*pc];

    for (int i = 3; i >= 0; --i) {
        arg_types[3 - i] = get_bits(coding_byte, i * 2, 2);
    }

    inc_pc(pc, 1);
}
