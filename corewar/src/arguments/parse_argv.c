/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** parse argv
*/

#include "my_stdio.h"

#include "corewar/corewar.h"

static bool parse_progs(int ac, char const *const *av, vm_t *vm)
{
    int start_av_from = (vm->nbr_cycles_to_dump == -1) ? 1 : 3;

    for (int i = start_av_from; i < ac; ++i)
        if (parse_prog(av, ac, vm, &i) == false)
            return false;

    if (check_progs_sizes(vm) == false)
        return false;

    return true;
}

static bool check_number_of_champs(vm_t *vm)
{
    if (vm->programs->size > MAX_PLAYERS) {
        my_dprintf(2, "Error: too much champions. (max 4)\n");
        return false;
    }
    if (vm->programs->size < 2) {
        my_dprintf(2, "Error: not enough champions. (min 2)\n");
        return false;
    }

    return true;
}

bool show_help(int ac, char const *const *av)
{
    for (int i = 0; i < ac; ++i) {
        if (my_streq(av[i], "-h") || my_streq(av[i], "--help")) {
            my_printf(HELP_MESSAGE, av[0]);
            return true;
        }
    }

    return false;
}

bool parse_argv(int ac, char const *const *av, vm_t *vm)
{
    if (ac < MIN_AC) {
        my_dprintf(2, "Error: invalid arg number %d\n", ac);
        return false;
    }
    if (ac > MIN_AC && parse_cycles(av, vm) == false) {
        return false;
    }
    if (parse_progs(ac, av, vm) == false) {
        return false;
    }
    if (check_number_of_champs(vm) == false) {
        return false;
    }
    return true;
}
