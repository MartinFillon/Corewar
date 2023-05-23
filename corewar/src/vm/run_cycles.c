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

static void UNUSED check_alive(vm_t *vm)
{
    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (vm->programs->data[i].program.is_alive == false) {
            vm->programs->data[i].is_running = false;
        }

        vm->programs->data[i].program.is_alive = false;
    }
}

static bool programs_alive(vm_t *vm)
{
    for (size_t i = 0; i < vm->programs->size; ++i)
        if (vm->programs->data[i].is_running == true)
            return true;

    return false;
}

static void print_winner(vm_t *vm)
{
    if (vm->last_live != NULL) {
        my_printf(
            "The player %d(%s)has won.\n",
            vm->last_live->registers[0],
            vm->last_live->header.prog_name
        );
    }
}

void run_vm(vm_t *vm)
{
    int nb_cycle = 0;

    while (programs_alive(vm)) {
        if (nb_cycle == vm->nbr_cycles_to_dump) {
            dump_memory(vm);
            return;
        }
        // if (nb_cycle > 0 && nb_cycle % CYCLE_TO_DIE == 0) {
        //     check_alive(vm);
        // }

        run_cycle(vm);

        if (vm->nbr_live >= NBR_LIVE) {
            vm->cycle_to_die -= CYCLE_DELTA;
            vm->nbr_live = 0;
        }
        nb_cycle++;
    }
    print_winner(vm);
}
