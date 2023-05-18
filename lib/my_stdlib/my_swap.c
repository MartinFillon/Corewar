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
    static char temp[MAX_SWAP_SIZE] = {0};

    assert(elem_size < MAX_SWAP_SIZE);

    my_memcpy(temp, b, elem_size);
    my_memcpy(b, a, elem_size);
    my_memcpy(a, temp, elem_size);
}
