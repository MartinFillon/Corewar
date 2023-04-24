/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** allocates memory and copies the string given in argument in it
*/

#include <stdlib.h>

#include "my_cstr.h"

char *my_strdup(char const *src)
{
    size_t length = my_strlen(src);
    char *dest = malloc(sizeof(char) * (length + 1));

    if (dest == NULL)
        return NULL;

    my_strcpy(dest, src);

    return dest;
}
