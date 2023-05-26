/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <stdlib.h>

#include "corewar/corewar.h"

int main(int ac, char const *const *av)
{
    vm_t vm = init_vm();

    if (show_help(ac, av) == true) {
        free_vm(&vm);
        return SUCCESS;
    }
    if (parse_argv(ac, av, &vm) == false || start_vm(&vm) == false) {
        free_vm(&vm);
        return ERROR;
    }

    run_vm(&vm);

    free_vm(&vm);
    return SUCCESS;
}
