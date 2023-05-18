/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** vm
*/

#include <stdlib.h>

#include "corewar/corewar.h"

void free_vm(vm_t *vm)
{
    free(vm->programs);
}

vm_t init_vm(void)
{
    vm_t vm = {
        .cycle = 0,
        .cycle_to_die = CYCLE_TO_DIE,
        .nbr_cycles = 0,
        .nbr_live = 0,
        .last_live = -1,
        .memory = {0},
        .programs = vec_create(100, sizeof(prog_t)),
    };

    return vm;
}
