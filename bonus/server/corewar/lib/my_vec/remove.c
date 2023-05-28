/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** remove from vector
*/

#include <stdlib.h>

#include "my_stdlib.h"
#include "my_vec.h"

void vec_remove(void *v, size_t idx)
{
    vec_t *vec = (vec_t*)v;

    my_memset(vec_at(vec, idx), 0, vec->_elem_size);
    if (idx < vec->size - 1) {
        my_memcpy(
            vec_at(vec, idx), vec_at(vec, idx + 1),
            (vec->size - idx) * vec->_elem_size
        );
    }
    vec->size--;
}

void vec_clear(void *v)
{
    vec_t *vec = (vec_t*)v;

    my_memset(vec->data, 0, vec->size * vec->_elem_size);
    vec->size = 0;
}

void vec_popback(void *v)
{
    vec_t *vec = (vec_t*)v;

    if (vec->size == 0)
        return;

    my_memset(vec_at(vec, vec->size), 0, vec->_elem_size);
    vec->size--;
}
