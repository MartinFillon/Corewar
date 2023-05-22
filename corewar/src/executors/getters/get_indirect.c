/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_indirect
*/

#include "corewar/op.h"

#include "corewar/corewar.h"

int get_indirect(u_char *memory, int memory_index)
{
    int direct = 0;

    for (int i = 0; i < IND_SIZE; i++) {
        direct <<= 8;
        direct += memory[memory_index + i];
    }
    return direct;
}
