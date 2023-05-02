/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** big_endian
*/

#include "asm/asm.h"

int convert_big_endian(int little)
{
    int pos[4] = {0, 0, 0, 0};
    int big = 0;

    pos[0] = (little & 0x000000ff) << OUTER_NUM;
    pos[1] = (little & 0x0000ff00) << INNER_NUM;
    pos[2] = (little & 0x00ff0000) >> INNER_NUM;
    pos[3] = (little & 0xff000000) >> OUTER_NUM;
    big = pos[0] | pos[1] | pos[2] | pos[3];
    return big;
}
