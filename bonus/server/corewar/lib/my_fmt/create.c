/*
** EPITECH PROJECT, 2023
** my_fmt
** File description:
** formatter
*/

#include <stdarg.h>
#include "my_stdlib.h"
#include "my_str.h"
#include "my_fmt.h"

void fmt_add_int(fmt_state_t *state);
void fmt_add_str(fmt_state_t *state);
void fmt_add_str_t(fmt_state_t *state);
void fmt_add_char(fmt_state_t *state);
void fmt_add_float(fmt_state_t *state);
void fmt_add_fast_float(fmt_state_t *state);
void fmt_add_lobase(fmt_state_t *state);
void fmt_add_upbase(fmt_state_t *state);
void fmt_add_join(fmt_state_t *state);

static const fmt_map_t FORMATS[] = {
    { '%', NULL },
    { 'c', &fmt_add_char },
    { 'S', &fmt_add_str_t },
    { 's', &fmt_add_str },
    { 'd', &fmt_add_int },
    { 'f', &fmt_add_float },
    { 'F', &fmt_add_fast_float },
    { 'b', &fmt_add_lobase },
    { 'B', &fmt_add_upbase },
    { 'j', &fmt_add_join },
};
static const int FORMATS_SIZE = sizeof(FORMATS) / sizeof(fmt_map_t);

static void check_precision(fmt_state_t *state, char const **str)
{
    if (**str != '.')
        return;

    ++*str;
    if (**str == '*') {
        state->precision = va_arg(*(state->ap), int);
        ++*str;
        return;
    }
    if (my_isnum(**str)) {
        state->precision = my_atoi(*str);
        while (my_isnum(*++*str));
    }
}

static void fill_state(fmt_state_t *state, char const **str)
{
    ++*str;
    check_precision(state, str);

    if (**str == 'l') {
        state->is_long = 1;
        ++*str;
    }
}

static void compute_format(fmt_state_t *state, char type)
{
    if (type == '%') {
        str_cadd(state->buffer, '%');
        return;
    }
    for (int i = 0; i < FORMATS_SIZE; ++i) {
        if (FORMATS[i].fmt == type) {
            FORMATS[i].fmt_fn(state);
            return;
        }
    }
}

void fmt_add(str_t **str, char const *fmt, va_list *ap)
{
    fmt_state_t state = {str, ap, 0, -1};

    while (*fmt) {
        if (*fmt == '%') {
            fill_state(&state, &fmt);
            compute_format(&state, *fmt);
        } else
            str_cadd(state.buffer, *fmt);
        fmt++;
    }
}

str_t *fmt_create(char const *fmt, va_list *ap)
{
    str_t *buffer = str_screate(my_strlen(fmt));

    fmt_add(&buffer, fmt, ap);

    return buffer;
}
