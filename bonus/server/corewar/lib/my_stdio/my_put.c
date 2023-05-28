/*
** EPITECH PROJECT, 2023
** my_puts.c
** File description:
** displays the characters of a string
*/

#include "my_stdio.h"
#include "my_str.h"

void my_puts(char const *str)
{
    my_putstr(str);
    my_putchar('\n');
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstderr(char const *str)
{
    write(2, str, my_strlen(str));
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
