/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_arg_types
*/

#include "corewar/corewar.h"
#include "corewar/instructions.h"

void get_arg_types(u_char *memory, int *pc, argument_t *arg_types)
{
    inc_pc(pc, 1);

    u_char coding_byte = memory[*pc];
    u_char arg_tp[4] = {0};

    for (int i = 3; i >= 0; --i) {
        arg_tp[3 - i] = get_bits(coding_byte, i * 2, 2);
    }

    for (int i = 0; i < 4; ++i) {
        arg_types[i].arg_type = arg_tp[i];
    }

    inc_pc(pc, 1);
}
