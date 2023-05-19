/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_direct
*/

#include "corewar/op.h"

#include "corewar/corewar.h"

int get_direct(char *memory, int memory_index)
{
    int direct = 0;

    for (int i = 0; i < DIR_SIZE; i++) {
        direct <<= 8;
        direct += memory[memory_index + i];
    }
    return swap_endian(direct);
}
