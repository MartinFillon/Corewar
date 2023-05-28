/*
** EPITECH PROJECT, 2023
** my_atoi.c
** File description:
** returns a number from a string
*/

#include "my_cstr.h"

long int my_atoi(char const *str)
{
    long int nb = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+')
        str++;

    while (*str && my_isnum(*str)) {
        nb = nb * 10 + (*str - '0');
        str++;
    }
    return nb * sign;
}
