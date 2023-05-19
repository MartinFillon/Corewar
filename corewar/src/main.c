/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "corewar/corewar.h"

int main(int ac, char const *const *av)
{
    vm_t vm = init_vm();

    if (show_help(ac, av) == true) {
        free_vm(&vm);
        return SUCCESS;
    }
    if (parse_argv(ac, av, &vm) == false) {
        free_vm(&vm);
        return ERROR;
    }
    if (start_vm(&vm) == false) {
        return ERROR;
    }

    // run_vm(&vm);

    // if (vm.nbr_cycles_to_dump != -1)
    dump_memory(&vm);

    free_vm(&vm);
    return SUCCESS;
}
