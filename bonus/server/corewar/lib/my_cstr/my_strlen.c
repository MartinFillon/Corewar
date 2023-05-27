/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** returns the number of characters of a string
*/

#include "my_cstr.h"

size_t my_strlen(char const *str)
{
    char const *start = str;

    while (*str++);

    return str - start - 1;
}
