/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** get_direct
*/

#include "corewar/op.h"

int get_direct(char *memory, int memory_index)
{
    int direct = 0;

    for (int i = 0; i < DIR_SIZE; i++) {
        direct <<= 8;
        direct += memory[memory_index + i];
    }
    return direct;
}
