/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** utils
*/

#include "my_str.h"

int str_count(str_t *str, char c)
{
    int count = 0;

    for (size_t i = 0; i < str->length; i++) {
        if (str->data[i] == c)
            count++;
    }
    return count;
}

int swap_endian_int(int val)
{
    return (
        (val & 0x000000ff) << 24 | (val & 0x0000ff00) << 8 |
        (val & 0x00ff0000) >> 8 | (val & 0xff000000) >> 24
    );
}
