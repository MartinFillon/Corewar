/*
** EPITECH PROJECT, 2023
** my_calloc.c
** File description:
** calloc small clone
*/

#include "my_stdlib.h"

void *my_realloc(void *ptr, size_t old_size, size_t size)
{
    void *temp = malloc(size);

    if (temp == NULL)
        return NULL;

    my_memcpy(temp, ptr, old_size);
    free(ptr);

    return temp;
}

void *my_calloc(size_t count, size_t elem_size)
{
    void *temp = malloc(count * elem_size);

    if (temp == NULL)
        return NULL;

    my_memset(temp, 0, count * elem_size);

    return temp;
}
