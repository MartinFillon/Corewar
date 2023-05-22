/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** write_int
*/

#include <sys/types.h>
#include "my_stdlib.h"

void write_int(char *memory, int index, int content)
{
    my_memcpy(memory + index, &content, sizeof(int));
}
