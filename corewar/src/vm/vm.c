/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** vm
*/

#include <stdlib.h>

#include "stdio.h"

#include "corewar/corewar.h"

void free_vm(vm_t *vm)
{
    dprintf(2, "free vm %ld\n", vm->programs->capacity);
    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (vm->programs->data[i].address != -1) {
            free(vm->programs->data[i].program.body);
        }
    }

    free(vm->programs);
}

vm_t init_vm(void)
{
    vm_t vm = {
        .cycle_to_die = CYCLE_TO_DIE,
        .nbr_cycles_to_dump = -1,
        .nbr_live = 0,
        .last_live = NULL,
        .arena = {0},
        .programs = vec_create(100, sizeof(prog_t)),
    };

    return vm;
}

void print_vm(vm_t *vm)
{
    dprintf(2,"vm {\n");
    dprintf(2,"\tcycle_to_die = %d\n", vm->cycle_to_die);
    dprintf(2,"\tnbr_cycles_to_dump = %d\n", vm->nbr_cycles_to_dump);
    dprintf(2,"\tnbr_live = %d\n", vm->nbr_live);
    dprintf(2,"\tlast_live = %p\n", vm->last_live);
    dprintf(2,"}\n");
}

bool start_vm(vm_t *vm)
{
    order_programs_by_number(vm->programs);

    if (load_programs(vm) == false)
        return false;

    vec_reverse(vm->programs);

    return true;
}
