/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_indirect
*/

#include "corewar/op.h"

#include "corewar/corewar.h"

int get_indirect(char *memory, int memory_index, int pc)
{
    int direct = 0;

    for (int i = 0; i < IND_SIZE; i++) {
        direct <<= 8;
        direct += memory[memory_index + i];
    }
    direct = swap_endian(direct);
    return memory[pc + direct];
}
