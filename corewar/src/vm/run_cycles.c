/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** run cycles
*/

#include "my_stdio.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/op.h"

static void check_alive(vm_t *vm)
{
    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (vm->programs->data[i].address == -1)
            continue;
        if (vm->programs->data[i].program.is_alive == false) {
            my_dprintf(
                2, "prog is dead %s\n",
                vm->programs->data[i].program.header.prog_name
            );
            vm->programs->data[i].is_running = false;
        }

        vm->programs->data[i].program.is_alive = false;
    }
}

static bool programs_alive(vm_t *vm)
{
    int count = 0;

    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (vm->programs->data[i].address == -1)
            continue;
        if (vm->programs->data[i].is_running == true)
            count++;
    }

    return count > 1;
}

static void print_winner(vm_t *vm)
{
    if (vm->last_live != NULL) {
        my_printf(
            "The player %d(%s)has won.\n", vm->last_live->registers[0],
            vm->last_live->header.prog_name
        );
    }
}

static void run_vm_init(vm_t *vm)
{
    vm->cycle_to_die = CYCLE_TO_DIE;

    for (size_t i = 0; i < vm->programs->size; ++i)
        update_cycle_to_wait(vm, &vm->programs->data[i].program);
}

void run_vm(vm_t *vm)
{
    int nb_cycle = 0;
    run_vm_init(vm);

    while (programs_alive(vm)) {
        if (nb_cycle == vm->nbr_cycles_to_dump) {
            dump_memory(vm);
            break;
        }
        if (nb_cycle > 0 && nb_cycle % vm->cycle_to_die == 0) {
            my_dprintf(
                2, "cycle_to_die: %d, nb_cycle %d, nbr_live %d\n",
                vm->cycle_to_die, nb_cycle, vm->nbr_live
            );
            my_dprintf(2, "last live: %s\n", vm->last_live->header.prog_name);
            check_alive(vm);
        }

        run_cycle(vm);

        if (vm->nbr_live >= NBR_LIVE) {
            my_dprintf(2, "nbr_live: %d\n", vm->nbr_live);
            vm->cycle_to_die -= CYCLE_DELTA;
            vm->nbr_live = 0;
        }
        nb_cycle++;
    }
    print_winner(vm);
}
