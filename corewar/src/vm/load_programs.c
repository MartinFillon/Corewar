/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** load programs into memory
*/

#include <stdbool.h>

#include "my_json.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"

static int get_total_programs_size(vec_prog_t *programs)
{
    int total_size = 0;

    for (size_t i = 0; i < programs->size; ++i)
        total_size += programs->data[i].program.header.prog_size;

    return total_size;
}

bool load_programs(vm_t *vm)
{
    vec_prog_t *programs = vm->programs;
    int total_size = get_total_programs_size(programs);
    int mem_gap = (MEM_SIZE - total_size) / programs->size;
    int mem_idx = 0;

    for (size_t i = 0; i < programs->size; ++i) {
        if (programs->data[i].address != -1)
            mem_idx = programs->data[i].address;

        my_memcpy(
            vm->memory + mem_idx, programs->data[i].program.body,
            programs->data[i].program.header.prog_size
        );
        mem_idx += programs->data[i].program.header.prog_size + mem_gap;
        mem_idx %= MEM_SIZE;
    }
    return true;
}
