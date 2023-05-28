/*
** EPITECH PROJECT, 2023
** my_atof
** File description:
** atof clone
*/

#include "my_cstr.h"

double my_atof(char const *str)
{
    double sign = 1;
    double nb = 0;
    double offset = 1;
    int found_dot = 0;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+')
        str++;
    while (*str && (my_isnum(*str) || (*str == '.' && !found_dot))) {
        if (*str == '.') {
            found_dot = 1;
        } else {
            nb = nb * 10 + (*str - '0');
            offset *= ((found_dot) ? 10 : 1);
        }
        str++;
    }
    return sign * (nb / offset);
}
