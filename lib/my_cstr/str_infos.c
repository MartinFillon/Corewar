/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** returns 1 if every chars of the string is alpha
*/

#include "my_cstr.h"

int my_str_isalpha(char const *str)
{
    if (*str == '\0')
        return 0;

    while (*str) {
        if (!my_isalpha(*str))
            return 0;
        str++;
    }

    return 1;
}

int my_str_isupper(char const *str)
{
    if (*str == '\0')
        return 0;

    while (*str) {
        if (!my_isupper(*str))
            return 0;
        str++;
    }

    return 1;
}

int my_str_isnum(char const *str)
{
    if (*str == '\0')
        return 0;

    while (*str) {
        if (!my_isnum(*str))
            return 0;
        str++;
    }

    return 1;
}

int my_str_islower(char const *str)
{
    if (*str == '\0')
        return 0;

    while (*str) {
        if (!my_islower(*str))
            return 0;
        str++;
    }

    return 1;
}
