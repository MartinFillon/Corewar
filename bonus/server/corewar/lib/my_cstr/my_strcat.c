/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** strcat and strncat
*/

#include "my_cstr.h"

char *my_strcat(char *dest, char const *src)
{
    char *start = dest;

    dest += my_strlen(dest);
    while (*src)
        *dest++ = *src++;
    *dest = '\0';

    return start;
}

char *my_strncat(char *dest, char const *src, size_t n)
{
    char *start = dest;
    dest += my_strlen(dest);

    while (n-- && *src)
        *dest++ = *src++;
    *dest = '\0';

    return start;
}
