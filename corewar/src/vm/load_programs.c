/*
** EPITECH PROJECT, 2022
** test123
** File description:
** load programs into memory
*/

#include <stdbool.h>

#include "my_stdio.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"

void order_programs_by_number(vec_prog_t *programs)
{
    int last_number = 0;

    for (size_t i = 0; i < programs->size; ++i) {
        if (programs->data[i].number == -1) {
            programs->data[i].number = last_number;
        }

        last_number = programs->data[i].number;
    }
}

bool load_programs(vm_t *vm)
{
    vec_prog_t *programs = vm->programs;

    int nbr_programs = programs->size;
    int interval = MEM_SIZE / nbr_programs;

    my_printf("interval = %d\n", interval);

    for (size_t i = 0; i < programs->size; ++i) {

        my_printf(
            "loading program %ld(%s)\n", i,
            programs->data[i].program.header.prog_name
        );
    }

    return true;
}
