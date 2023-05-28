/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** misc
*/

#include "my_cstr.h"

char *my_revstr(char *str)
{
    size_t length = my_strlen(str);
    size_t idx = 0;
    char temp = '\0';

    while (idx < length / 2) {
        temp = str[idx];
        str[idx] = str[length - idx - 1];
        str[length - idx - 1] = temp;
        idx++;
    }

    return str;
}

char *my_strchr(char *str, char c)
{
    while (*str && *str != c)
        str++;

    if (*str == c)
        return str;
    return NULL;
}

int my_str_isint(char const *str)
{
    if (*str == '\0')
        return 0;

    if (*str == '-' || *str == '+')
        str++;

    while (*str) {
        if (!my_isnum(*str))
            return 0;
        str++;
    }
    return 1;
}

int my_str_isfloat(char const *str)
{
    int found_dot = 0;

    if (*str == '\0')
        return 0;

    if (*str == '-' || *str == '+')
        str++;

    while (*str) {
        if (!my_isnum(*str) && (*str != '.' || found_dot))
            return 0;
        found_dot |= (*str == '.');
        str++;
    }
    return 1;
}

int my_streq(char const *s1, char const *s2)
{
    return (my_strlen(s1) == my_strlen(s2) && my_strcmp(s1, s2) == 0);
}
