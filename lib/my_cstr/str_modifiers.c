/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** puts every letter in lowercase/uppercase
*/

#include "my_cstr.h"

char *my_strlowcase(char *str)
{
    for (size_t i = 0; str[i]; i++)
        str[i] = my_lowcase(str[i]);

    return str;
}

char *my_strupcase(char *str)
{
    for (size_t i = 0; str[i]; i++)
        str[i] = my_upcase(str[i]);

    return str;
}
