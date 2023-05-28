/*
** EPITECH PROJECT, 2023
** my_memcpy
** File description:
** memcpy
*/

#include "my_stdlib.h"

void *my_memset(void *dest, unsigned char c, size_t len)
{
    unsigned char *dest_chr = dest;

    while (len--)
        *dest_chr++ = c;

    return dest;
}
