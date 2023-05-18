/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/op.h"

static bool parse_argv(int ac, char const *const *av, vm_t *vm)
{
    int start_av_from = START_AV;

    if (ac < MIN_AC) {
        my_dprintf(2, "Error: invalid arg number %d\n", ac);
        return false;
    }
    if (ac > MIN_AC && parse_cycles(av, vm, &start_av_from) == false)
        return false;
    for (int i = start_av_from; i < ac; ++i)
        if (parse_prog(av, ac, vm, &i) == false)
            return false;

    if (vm->programs->size > MAX_PLAYERS) {
        my_dprintf(2, "Error: too much champions. (max 4)\n");
        return false;
    }
    return true;
}

void start_vm(vm_t *vm)
{
    print_vm(vm);

    order_programs_by_number(vm->programs);
    load_programs(vm);
}

int main(int ac, char const *const *av)
{
    vm_t vm = init_vm();

    if (parse_argv(ac, av, &vm) == false) {
        free_vm(&vm);
        return ERROR;
    }

    start_vm(&vm);

    free_vm(&vm);
    return SUCCESS;
}
