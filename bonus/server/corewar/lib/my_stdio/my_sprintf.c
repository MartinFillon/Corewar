/*
** EPITECH PROJECT, 2023
** my_stdio
** File description:
** clone of sprintf
*/

#include <stdarg.h>

#include "my_fmt.h"
#include "my_stdlib.h"
#include "my_str.h"

char *my_sprintf(const char *fmt, ...)
{
    va_list ap;
    str_t *buff = NULL;
    char *cstr = NULL;

    va_start(ap, fmt);
    buff = fmt_create(fmt, &ap);
    va_end(ap);

    cstr = my_strdup(str_tocstr(buff));
    free(buff);

    return cstr;
}
