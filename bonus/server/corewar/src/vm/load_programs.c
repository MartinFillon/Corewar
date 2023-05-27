/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** load programs into memory
*/

#include "my_stdio.h"
#include "my_stdlib.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"

static bool check_overlap(vm_t *vm, int mem_idx, int prog_size)
{
    for (int i = 0; i < prog_size; ++i) {
        if (vm->arena[(mem_idx + i) % MEM_SIZE] != 0) {
            my_dprintf(2, "Error: overlap detected\n");
            return true;
        }
    }

    return false;
}

bool load_programs(vm_t *vm)
{
    vec_prog_t *programs = vm->programs;
    int mem_gap = MEM_SIZE / programs->size;
    int mem_idx = 0;

    for (size_t i = 0; i < programs->size; ++i) {
        program_t *p = &programs->data[i].program;

        if (programs->data[i].address != -1)
            mem_idx = programs->data[i].address;
        if (check_overlap(vm, mem_idx, p->header.prog_size))
            return false;

        programs->data[i].address = mem_idx;
        programs->data[i].program.pc = mem_idx;
        my_memcpy(vm->arena + mem_idx, p->body, p->header.prog_size);
        mem_idx = (mem_idx + mem_gap) % MEM_SIZE;
    }
    return true;
}
