/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** str from int / long int / double
*/

#include "my_stdlib.h"
#include "my_str.h"

str_t *my_itostr(long int nb)
{
    char *tmp = my_itoa(nb);
    str_t *str = str_create(tmp);
    free(tmp);
    return str;
}

str_t *my_ftostr(double nb, int precision)
{
    char *tmp = my_ftoa(nb, precision);
    str_t *str = str_create(tmp);
    free(tmp);
    return str;
}
