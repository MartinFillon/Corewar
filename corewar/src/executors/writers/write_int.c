/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** write_int
*/

#include "my_stdio.h"
#include "my_stdlib.h"

#include "corewar/corewar.h"
#include "corewar/op.h"

void write_int(u_char *memory, int index, int content)
{
    if (index + sizeof(int) < MEM_SIZE) {
        my_memcpy(&memory[index], &content, sizeof(int));
    }
}
