/*
** EPITECH PROJECT, 2023
** my_stdlib
** File description:
** my_memcmp
*/

#include "my_stdlib.h"

int my_memcmp(void const *m1, void const *m2, size_t n)
{
    char const *s1 = m1;
    char const *s2 = m2;

    if (n == 0)
        return 0;

    while (--n && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}
