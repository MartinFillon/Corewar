/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compare
*/

#include "my_stdlib.h"
#include "my_utils.h"
#include "my_str.h"

int str_eq(str_t const *s1, str_t const *s2)
{
    if (s1->length != s2->length)
        return 0;

    return (str_compare(s1, s2) == 0);
}

int str_ncompare(str_t const *s1, str_t const *s2, size_t n)
{
    size_t min = MIN(n, MIN(s1->length, s2->length));

    return my_memcmp(s1->data, s2->data, min);
}

int str_compare(str_t const *s1, str_t const *s2)
{
    size_t min = MIN(s1->length, s2->length);

    return my_memcmp(s1->data, s2->data, min);
}
