/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** order the programs
*/

#include <stdbool.h>

#include "my_stdio.h"
#include "my_vec.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"

static vec_int_t *find_used_numbers(vec_prog_t *programs)
{
    vec_int_t *used_numbers = vec_create(programs->size, sizeof(int));

    for (size_t i = 0; i < programs->size; ++i)
        if (programs->data[i].number != -1)
            vec_pushback(&used_numbers, &programs->data[i].number);

    return used_numbers;
}

static bool is_number_used(vec_int_t *used_numbers, int number)
{
    for (size_t i = 0; i < used_numbers->size; ++i)
        if (used_numbers->data[i] == number)
            return true;

    return false;
}

static int get_next_available_number(vec_int_t *used_numbers, int from)
{
    int number = from;

    while (is_number_used(used_numbers, number))
        number++;

    return number;
}

static int order_by_number(const void *a, const void *b)
{
    prog_t const *prog_a = a;
    prog_t const *prog_b = b;

    return prog_a->number - prog_b->number;
}

void order_programs_by_number(vec_prog_t *programs)
{
    vec_int_t *used_numbers = find_used_numbers(programs);
    int number = get_next_available_number(used_numbers, 0);

    for (size_t i = 0; i < programs->size; ++i) {
        if (programs->data[i].number != -1)
            continue;

        programs->data[i].number = number;
        number = get_next_available_number(used_numbers, number + 1);
    }

    vec_sort(programs, &order_by_number);
    vec_reverse(programs);
}
