/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read_int
*/

#include "my_stdlib.h"

#include "corewar/corewar.h"

int read_int(u_char *memory, int index)
{
    int val = 0;

    if (index + sizeof(int) < MEM_SIZE) {
        my_memcpy(&val, &memory[index], sizeof(int));
    }

    return val;
}
