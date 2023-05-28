/*
** EPITECH PROJECT, 2022
** navy
** File description:
** convert
*/

#include "my_stdlib.h"
#include "my_str.h"

long int str_toint(str_t *str)
{
    return my_atoi(str->data);
}

double str_tofloat(str_t *str)
{
    return my_atof(str->data);
}

char *str_tocstr(str_t *str)
{
    return str->data;
}
