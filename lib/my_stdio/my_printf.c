/*
** EPITECH PROJECT, 2023
** my_stdio
** File description:
** clone of printf
*/

#include <stdarg.h>

#include "my_stdlib.h"
#include "my_str.h"
#include "my_fmt.h"

int my_printf(const char *fmt, ...)
{
    va_list ap;
    str_t *buff = NULL;
    size_t len = 0;

    va_start(ap, fmt);
    buff = fmt_create(fmt, &ap);
    va_end(ap);

    str_print(buff);
    len = buff->length;
    free(buff);

    return len;
}
