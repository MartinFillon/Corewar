/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read_int
*/

#include "my_stdlib.h"

int read_int(u_char *memory, int index)
{
    int i = 0;
    my_memcpy(&i, memory + index, sizeof(int));
    return i;
}
