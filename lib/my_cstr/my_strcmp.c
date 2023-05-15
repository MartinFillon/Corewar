/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** strcmp and strncmp
*/

#include "my_cstr.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int my_strncmp(char const *s1, char const *s2, size_t n)
{
    while (--n && *s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int my_strstartwith(char const *str, char const *start)
{
    size_t start_len = my_strlen(start);

    if (my_strlen(str) < start_len)
        return 0;

    return my_strncmp(str, start, start_len);
}

int my_strendwith(char const *str, char const *end)
{
    size_t str_len = my_strlen(str);
    size_t end_len = my_strlen(end);

    if (str_len < end_len)
        return 0;

    return my_strncmp(str + str_len - end_len, end, end_len);
}
