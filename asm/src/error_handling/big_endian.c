/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** big_endian
*/

#include "asm/asm.h"

int swap_endian(int val)
{
    return (
        (val & 0x000000ff) << 24 | (val & 0x0000ff00) << 8 |
        (val & 0x00ff0000) >> 8 | (val & 0xff000000) >> 24
    );
}
