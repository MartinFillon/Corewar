/*
** EPITECH PROJECT, 2023
** my_fmt
** File description:
** formatter declarations
*/

#ifndef INCLUDE_MY_FMT_
    #define INCLUDE_MY_FMT_
    #include <stdarg.h>
    #include <stdint.h>

    #include "my_str.h"

/**
 * @category formats
 *
 * @param %% -> %
 * @param %c -> char
 * @param %S -> str_t
 * @param %s -> string
 * @param %d -> int
 * @param %j -> join vector : expected join delim
 * @param %f -> float
 * @param %b -> base lowercase : expected base
 * @param %B -> base uppercase : expected base
 *
 * @category width <NOT SUPPORTED>
 *
 * @param * -> width in va_arg <NOT SUPPORTED>
 * @param X -> width <NOT SUPPORTED>
 *
 * @category precision
 *
 * @param .* -> prec in va_arg
 * @param .X -> prec
 *
 * @category type indicator
 *
 * @param l -> long
 */

typedef struct fmt_state_s {
    str_t **buffer;
    va_list *ap;
    char is_long;
    int precision;
} fmt_state_t;

typedef struct fmt_map_s {
    char fmt;
    void (*fmt_fn)(fmt_state_t *);
} fmt_map_t;

/**
 * @brief creates a formated string
 *
 * @param fmt   the format
 * @param ap    the va_list
 * @return the formatted string
 */
str_t *fmt_create(char const *fmt, va_list *ap);

/**
 * @brief adds a formated string to an existing string
 *
 * @param str   the string to add to
 * @param fmt   the format to use
 * @param ap    the va_list to use
 */
void fmt_add(str_t **str, char const *fmt, va_list *ap);


#endif /* INCLUDE_MY_FMT_ */
