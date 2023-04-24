/*
** EPITECH PROJECT, 2023
** my_fmt
** File description:
** add base
*/

#include <stdarg.h>
#include "my_stdlib.h"
#include "my_str.h"
#include "my_fmt.h"

static void fmt_add_base(fmt_state_t *state, int is_upper)
{
    unsigned long int nb = va_arg(*(state->ap), unsigned long int);
    int base = va_arg(*(state->ap), int);
    int len = my_nbrlen(nb, base);
    char *res = malloc(sizeof(char) * (len + 1));
    res[len] = '\0';
    int i = len - 1;

    while (nb) {
        if (nb % base < 9)
            res[i--] = (nb % base) + '0';
        else
            res[i--] = (nb % base - 9) + ((is_upper) ? 'A' : 'a');
        nb /= base;
    }

    str_add(state->buffer, res);
    free(res);
}

void fmt_add_lobase(fmt_state_t *state)
{
    fmt_add_base(state, 0);
}

void fmt_add_upbase(fmt_state_t *state)
{
    fmt_add_base(state, 1);
}
