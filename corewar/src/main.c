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
    if (ac < MIN_AC || (ac > MIN_AC && parse_cycles(av, vm) == false)) {
        my_dprintf(2, "Error: invalid args, %d\n", ac);
        return false;
    }

    for (int i = START_AV; i < ac; ++i)
        if (parse_prog(av, ac, vm, &i) == false)
            return false;

    return true;
}

int main(int ac, char const *const *av)
{
    vm_t vm = init_vm();

    if (parse_argv(ac, av, &vm) == false) {
        return ERROR;
    }

    print_progs(vm.programs);

    free_vm(&vm);
    return SUCCESS;
}
