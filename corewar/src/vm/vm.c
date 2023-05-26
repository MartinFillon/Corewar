/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** vm
*/

#include "my_stdio.h"
#include "my_stdlib.h"

#include "corewar/corewar.h"

void free_vm(vm_t *vm)
{
    for (size_t i = 0; i < vm->programs->size; ++i)
        if (vm->programs->data[i].program.body != NULL)
            free(vm->programs->data[i].program.body);

    free(vm->programs);
}

vm_t init_vm(void)
{
    vm_t vm = {
        .cycle_to_die = CYCLE_TO_DIE,
        .nbr_cycles_to_dump = -1,
        .nbr_live = 0,
        .last_live = NULL,
        .programs = vec_create(512, sizeof(prog_t)),
        .arena = {0},
    };

    return vm;
}

void print_vm(vm_t *vm)
{
    my_dprintf(2, "vm {\n");
    my_dprintf(2, "\tcycle_to_die = %d\n", vm->cycle_to_die);
    my_dprintf(2, "\tnbr_cycles_to_dump = %d\n", vm->nbr_cycles_to_dump);
    my_dprintf(2, "\tnbr_live = %d\n", vm->nbr_live);
    my_dprintf(2, "\tlast_live = %p\n", vm->last_live);
    my_dprintf(2, "}\n");
}

bool start_vm(vm_t *vm)
{
    order_programs_by_number(vm->programs);

    if (load_programs(vm) == false)
        return false;

    vec_reverse(vm->programs);

    return true;
}
