/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_arg_types
*/

#include "corewar/corewar.h"

void get_arg_types(char *memory, int memory_index, u_char *arg_types)
{
    u_char coding_byte = memory[memory_index];

    for (int i = 3; i >= 0; --i) {
        arg_types[i] = get_bits(coding_byte, i * 2, 2);
    }
}
