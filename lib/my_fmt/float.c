/*
** EPITECH PROJECT, 2023
** my_fmt
** File description:
** float adders
*/

#include "my_fmt.h"
#include "my_stdlib.h"

void fmt_add_float(fmt_state_t *state)
{
    double data = va_arg(*(state->ap), double);
    int precision = (state->precision == -1) ? 6 : state->precision;
    char *temp = my_ftoa(data, precision);

    str_add(state->buffer, temp);
    free(temp);
}

void fmt_add_fast_float(fmt_state_t *state)
{
    double data = va_arg(*(state->ap), double);
    int precision = (state->precision == -1) ? 6 : state->precision;
    char *temp = my_fftoa(data, precision);

    str_add(state->buffer, temp);
    free(temp);
}
