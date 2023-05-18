/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parse_arguments
*/

#include "my_cstr.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"

bool parse_cycles(char const *const *av, vm_t *vm)
{
    if (my_streq(av[1], "-dump")) {
        if (!my_str_isnum(av[2])) {
            my_dprintf(2, "Error: invalid dump args\n");
            return false;
        }

        vm->nbr_cycles = my_atoi(av[2]);
    }

    return true;
}

static int parse_prog_number(
    int ac, char const *const *av, int *j, prog_t *prog
)
{
    if (my_streq(av[*j], "-n")) {
        ++*j;

        if (*j >= ac || !my_str_isnum(av[*j])) {
            return ERROR;
        }

        prog->number = my_atoi(av[*j]);
        return true;
    }

    return false;
}

static int parse_prog_adress(
    int ac, char const *const *av, int *j, prog_t *prog
)
{
    if (my_streq(av[*j], "-a")) {
        ++*j;

        if (*j >= ac || !my_str_isnum(av[*j])) {
            return ERROR;
        }

        prog->address = my_atoi(av[*j]);
        return true;
    }

    return false;
}

bool parse_prog(char const *const *av, int ac, vm_t *vm, int *i)
{
    prog_t tmp = init_prog();
    int max_prog_av = *i + MAX_PROG_AV;
    int ret = 0;

    for (; *i < max_prog_av && *i < ac; ++*i) {
        ret = parse_prog_number(ac, av, i, &tmp);
        if (ret == ERROR)
            return false;
        if (ret)
            continue;
        ret = parse_prog_adress(ac, av, i, &tmp);
        if (ret == ERROR)
            return false;
        if (ret)
            continue;
        return check_and_read_prog(vm, &tmp, av[*i]);
    }
    return false;
}
