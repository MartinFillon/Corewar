/*
** EPITECH PROJECT, 2023
** my_stdlib
** File description:
** generic swap
*/

#include <assert.h>

#include "my_stdlib.h"

void my_swap(void *a, void *b, size_t elem_size)
{
    char *char_a = a;
    char *char_b = b;
    char tmp = 0;

    do {
        tmp = *char_a;
        *char_a++ = *char_b;
        *char_b++ = tmp;
    } while (--elem_size > 0);
}
