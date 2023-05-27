/*
** EPITECH PROJECT, 2023
** my_stdio
** File description:
** my_stdio declarations
*/

#ifndef INCLUDE_MY_STDIO_
    #define INCLUDE_MY_STDIO_
    #include <unistd.h>
    #include <stdarg.h>

    #include "my_str.h"


int my_printf(const char *format, ...);
int my_dprintf(int fd, const char * format, ...);

char *my_sprintf(const char *fmt, ...);

void my_putchar(char c);
void my_putstr(char const *str);
void my_putstderr(char const *str);
void my_puts(char const *str);
str_t *read_file(char const *file_path);


#endif /* INCLUDE_MY_STDIO_ */
