/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** run cycles
*/

#include "stdio.h"

#include "my_stdio.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/op.h"

static void print_winner(vm_t *vm)
{
    if (vm->last_live != NULL) {
        my_printf(
            "The player %d(%s)has won.\n", vm->last_live->number,
            vm->last_live->program.header.prog_name
        );
        my_dprintf(
            2, "{\"action\":\"winner\",\"pid\":%d}\n",
            vm->last_live->program.pid
        );
    }
}

static void run_vm_init(vm_t *vm)
{
    vm->cycle_to_die = CYCLE_TO_DIE;
    my_dprintf(
        2, "{\"action\":\"cycle_to_die\",\"cycle_to_die\":%d}\n",
        vm->cycle_to_die
    );

    for (size_t i = 0; i < vm->programs->size; ++i)
        update_cycle_to_wait(vm, &vm->programs->data[i].program);
}

void run_vm(vm_t *vm)
{
    int nb_cycle = 0;
    run_vm_init(vm);

    while (programs_alive(vm)) {
        if (nb_cycle % 3 == 0) {
            my_dprintf(2, "{\"action\":\"cycle\",\"nb_cycle\":%d}\n", nb_cycle);
        }
        if (nb_cycle == vm->nbr_cycles_to_dump) {
            dump_memory(vm);
            break;
        }
        if (vm->cycle_to_die < 0 ||
            (nb_cycle > 0 && nb_cycle % vm->cycle_to_die == 0)) {
            check_alive(vm);
        }
        if (vm->nbr_live >= NBR_LIVE) {
            vm->cycle_to_die -= CYCLE_DELTA;
            my_dprintf(
                2, "{\"action\":\"cycle_to_die\",\"cycle_to_die\":%d}\n",
                vm->cycle_to_die
            );
            vm->nbr_live = 0;
        }

        run_cycle(vm);
        nb_cycle++;
    }
    print_winner(vm);
}
