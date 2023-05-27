/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** alive
*/

#include "my_stdio.h"

#include "corewar/corewar.h"

static void kill_children(vec_prog_t *progs, int number)
{
    for (size_t i = 0; i < progs->size; ++i) {
        if (progs->data[i].address != -1)
            continue;

        if (progs->data[i].program.pid == number) {
            progs->data[i].is_running = false;
        }
    }
}

void check_alive(vm_t *vm)
{
    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (vm->programs->data[i].address == -1)
            continue;

        if (vm->programs->data[i].program.is_alive == false) {
            vm->programs->data[i].is_running = false;
            my_dprintf(
                2, "{\"action\":\"dead\",\"pid\":%d}\n",
                vm->programs->data[i].number
            );
            kill_children(vm->programs, vm->programs->data[i].number);
        }

        vm->programs->data[i].program.is_alive = false;
    }
}

bool programs_alive(vm_t *vm)
{
    size_t count = 0;

    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (vm->programs->data[i].address == -1)
            continue;
        if (vm->programs->data[i].is_running == true)
            count++;
    }

    return count > 1;
}
