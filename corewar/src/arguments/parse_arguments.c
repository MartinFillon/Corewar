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

bool parse_cycles(char const *const *av, vm_t *vm, int *start_av_from)
{
    if (my_streq(av[1], "-dump")) {
        if (!my_str_isnum(av[2])) {
            my_dprintf(2, "Error: invalid dump (-dump) value\n");
            return false;
        }

        vm->nbr_cycles_to_dump = my_atoi(av[2]);
        *start_av_from += 2;
    }

    return true;
}

static int parse_prog_number(
    int ac, char const *const *av, int *i, prog_t *prog
)
{
    if (my_streq(av[*i], "-n")) {
        ++*i;

        if (*i >= ac || !my_str_isnum(av[*i])) {
            my_dprintf(2, "Error: invalid number (-n) value\n");
            return ERROR;
        }
        prog->number = my_atoi(av[*i]);
        if (prog->number < 1 || prog->number > MAX_PLAYERS) {
            my_dprintf(2, "Error: invalid number for player, (1, 2, 3, 4)\n");
            return ERROR;
        }
        return true;
    }

    return false;
}

static int parse_prog_address(
    int ac, char const *const *av, int *i, prog_t *prog
)
{
    if (my_streq(av[*i], "-a")) {
        ++*i;

        if (*i >= ac || !my_str_isnum(av[*i])) {
            my_dprintf(2, "Error: invalid address (-a) value\n");
            return ERROR;
        }

        prog->address = my_atoi(av[*i]) % MEM_SIZE;
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
        ret = parse_prog_address(ac, av, i, &tmp);
        if (ret == ERROR)
            return false;
        if (ret)
            continue;
        return check_and_read_prog(vm, &tmp, av[*i]);
    }
    return false;
}
