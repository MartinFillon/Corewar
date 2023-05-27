/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** misc
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "my_utils.h"
#include "my_vec.h"

str_t **str_resize(str_t **str, size_t new_size)
{
    size_t new_cap = get_padded_size(new_size);
    str_t *old = *str;

    *str = my_realloc(
        old, sizeof(str_t) + sizeof(char) * old->capacity,
        sizeof(str_t) + sizeof(char) * new_cap
    );
    (*str)->capacity = new_cap;

    return str;
}

long str_find(str_t const *str, str_t const *find, size_t start)
{
    if (find->length > str->length)
        return -1;

    if (start >= str->length)
        return -1;

    for (size_t i = start; i < str->length - find->length; ++i)
        if (my_strncmp(str->data + i, find->data, find->length) == 0)
            return i;

    return -1;
}
