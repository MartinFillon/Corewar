/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** puts a letter in lowercase/uppercase
*/

#include "my_cstr.h"

char my_lowcase(char chr)
{
    if (my_isupper(chr))
        return (chr - ('A' - 'a'));
    else
        return chr;
}

char my_upcase(char chr)
{
    if (my_islower(chr))
        return (chr - ('a' - 'A'));
    else
        return chr;
}
