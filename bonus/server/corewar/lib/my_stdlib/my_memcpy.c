/*
** EPITECH PROJECT, 2023
** my_memcpy
** File description:
** memcpy
*/

#include "my_stdlib.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *dest_chr = dest;
    char const *src_chr = src;

    while (n--)
        *dest_chr++ = *src_chr++;

    return dest;
}
