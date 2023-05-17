/*
** EPITECH PROJECT, 2023
** my_fmt
** File description:
** adders
*/

#include "my_stdlib.h"
#include "my_fmt.h"

void fmt_add_int(fmt_state_t *state)
{
    long int data = (state->is_long) ?
        va_arg(*state->ap, long int) :
        va_arg(*state->ap, int);
    char *temp = my_itoa(data);

    str_add(state->buffer, temp);
    free(temp);
}

void fmt_add_str(fmt_state_t *state)
{
    char *data = va_arg(*state->ap, char *);

    str_add(state->buffer, data);
}

void fmt_add_str_t(fmt_state_t *state)
{
    str_t *data = va_arg(*state->ap, str_t *);

    str_sadd(state->buffer, data);
}

void fmt_add_char(fmt_state_t *state)
{
    char data = va_arg(*state->ap, int);

    str_cadd(state->buffer, data);
}
