/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parse_arguments
*/

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_cstr.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"

bool parse_cycles(char **av, arguments_t *args)
{
    if (my_streq(av[1], "-dump")) {
        if (!my_str_isnum(av[2])) {
            dprintf(2, "Error: invalid dump args\n");
            return false;
        }
        args->nbr_cycles = my_atoi(av[2]);
    }

    return true;
}

static int parse_prog_number(int ac, char **av, int *j, prog_t *tmp)
{
    if (my_streq(av[*j], "-n")) {
        ++*j;
        if (*j >= ac || !my_str_isnum(av[*j]))
            return ERROR;
        tmp->number = my_atoi(av[*j]);
        return true;
    }

    return false;
}

static int parse_prog_adress(int ac, char **av, int *j, prog_t *tmp)
{
    if (my_streq(av[*j], "-a")) {
        ++*j;
        if (*j >= ac || !my_str_isnum(av[*j]))
            return ERROR;
        tmp->adress = my_atoi(av[*j]);
        return true;
    }

    return false;
}

static bool check_file(arguments_t *args, prog_t *prog)
{
    if (my_strendwith(prog->path, ".cor") == false) {
        dprintf(2, "Error: %s is not a .cor file\n", prog->path);
        return false;
    }

    prog->fd = open(prog->path, O_RDONLY);
    if (prog->fd < 0) {
        dprintf(2, "Error: Can't read .cor file %s\n", prog->path);
        return false;
    }

    vec_pushback(&args->programs, prog);
    return true;
}

bool parse_prog(char **av, int ac, arguments_t *args, int *i)
{
    prog_t tmp = {0, 0, NULL, -1, {0}, NULL, NULL};
    int max_i = *i + MAX_PROG_AV;
    int ret = 0;

    for (; *i < max_i && *i < ac; ++*i) {
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
        tmp.path = my_strdup(av[*i]);
        return check_file(args, &tmp);
    }
    return false;
}
