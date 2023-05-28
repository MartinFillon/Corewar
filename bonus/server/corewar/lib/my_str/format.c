/*
** EPITECH PROJECT, 2023
** antman
** File description:
** format utils
*/

#include <stdarg.h>

#include "my_fmt.h"
#include "my_stdlib.h"
#include "my_str.h"

str_t **str_fadd(str_t **str, char const *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    fmt_add(str, fmt, &ap);
    va_end(ap);

    return str;
}
