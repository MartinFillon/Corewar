/*
** EPITECH PROJECT, 2023
** my_dprintf
** File description:
** dprintf clone
*/

#include <stdarg.h>

#include "my_fmt.h"
#include "my_stdlib.h"
#include "my_str.h"

int my_dprintf(int fd, const char *fmt, ...)
{
    va_list ap;
    str_t *buff = NULL;
    size_t len = 0;

    va_start(ap, fmt);
    buff = fmt_create(fmt, &ap);
    va_end(ap);

    str_dprint(fd, buff);
    len = buff->length;
    free(buff);

    return len;
}
