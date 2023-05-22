/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** vm
*/

#include <stdlib.h>

#include "my_stdio.h"

#include "corewar/corewar.h"

void free_vm(vm_t *vm)
{
    for (size_t i = 0; i < vm->programs->size; ++i)
        free(vm->programs->data[i].program.body);

    free(vm->programs);
}

vm_t init_vm(void)
{
    vm_t vm = {
        .cycle = 0,
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
    my_printf("vm {\n");
    my_printf("\tcycle = %d\n", vm->cycle);
    my_printf("\tcycle_to_die = %d\n", vm->cycle_to_die);
    my_printf("\tnbr_cycles_to_dump = %d\n", vm->nbr_cycles_to_dump);
    my_printf("\tnbr_live = %d\n", vm->nbr_live);
    my_printf("\tlast_live = %d\n", vm->last_live);
    my_printf("}\n");
}

bool start_vm(vm_t *vm)
{
    order_programs_by_number(vm->programs);

    if (load_programs(vm) == false)
        return false;

    vec_reverse(vm->programs);

    return true;
}
