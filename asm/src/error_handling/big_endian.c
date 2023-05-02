/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** big_endian
*/

#include "asm/asm.h"

int convert_big_endian(int little)
{
    return (
        (little & 0x000000ff) << 24 |
        (little & 0x0000ff00) << 8 |
        (little & 0x00ff0000) >> 8 |
        (little & 0xff000000) >> 24
    );
}
