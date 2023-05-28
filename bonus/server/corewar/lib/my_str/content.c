/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** content checks
*/

#include "my_str.h"

int str_isalpha(str_t const *str)
{
    if (str->length == 0)
        return 0;

    for (size_t i = 0; i < str->length; ++i)
        if (!my_isalpha(str->data[i]))
            return 0;

    return 1;
}

int str_isnum(str_t const *str)
{
    if (str->length == 0)
        return 0;

    for (size_t i = 0; i < str->length; ++i)
        if (!my_isnum(str->data[i]))
            return 0;

    return 1;
}

int str_isalphanum(str_t const *str)
{
    if (str->length == 0)
        return 0;

    for (size_t i = 0; i < str->length; ++i)
        if (!my_isnum(str->data[i]) && !my_isalpha(str->data[i]))
            return 0;

    return 1;
}
