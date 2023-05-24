/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** order the programs
*/

#include <stdbool.h>
#include <stddef.h>

#include "my_stdio.h"
#include "my_vec.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"

static void fill_used_numbers(vec_prog_t *programs, bool *used_numbers)
{
    for (size_t i = 0; i < programs->size; ++i)
        if (programs->data[i].number != -1)
            used_numbers[programs->data[i].number - 1] = true;
}

static int get_next_available_number(bool *used_numbers)
{
    int i = 0;

    while (i < MAX_PLAYERS && used_numbers[i])
        i++;

    used_numbers[i] = true;

    return i;
}

static int order_by_number(const void *a, const void *b)
{
    prog_t const *prog_a = a;
    prog_t const *prog_b = b;

    return prog_b->number - prog_a->number;
}

void order_programs_by_number(vec_prog_t *programs)
{
    bool *used_numbers = (bool[4]){0, 0, 0, 0};
    fill_used_numbers(programs, used_numbers);

    for (long i = programs->size; i >= 0; --i) {
        if (programs->data[i].number != -1)
            continue;

        programs->data[i].number = get_next_available_number(used_numbers) + 1;
    }

    vec_sort(programs, &order_by_number);

    for (size_t i = 0; i < programs->size; ++i)
        programs->data[i].program.registers[0] = programs->data[i].number;
}
