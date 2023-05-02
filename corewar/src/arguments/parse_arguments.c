/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parse_arguments
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_cstr.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"

int parse_cycles(char **av, arguments_t *args)
{
    if (my_strcmp(av[1], "-dump") == 0) {
        if (!my_str_isnum(av[2]))
            return 84;
        args->nbr_cycles = my_atoi(av[2]);
    }
    return 0;
}

static int parse_prog_number(char **av, int *j, int ac, prog_t *tmp)
{
    if (!my_strcmp(av[*j], "-n")) {
            *j += 1;
        if (*j >= ac || !my_str_isnum(av[*j]))
            return 84;
        tmp->number = my_atoi(av[*j]);
        return 1;
    }
    return 0;
}

static int parse_prog_adress(char **av, int *j, int ac, prog_t *tmp)
{
    if (!my_strcmp(av[*j], "-a")) {
        *j += 1;
        if (*j >= ac || !my_str_isnum(av[*j]))
            return 84;
        tmp->adress = my_atoi(av[*j]);
        return 1;
    }
    return 0;
}

static int check_file(arguments_t *args, prog_t *prog)
{
    int fd = open(prog->path, O_RDONLY);
    if (fd == -1)
        return 84;
    close(fd);
    vec_pushback(&args->programs, prog);
    return 0;
}

int parse_prog(char **av, int ac, arguments_t *args, int *i)
{
    prog_t tmp = {0, 0, NULL};
    int j = *i;
    int ret = 0;

    for (; j < *i + 5 && j < ac; j++) {
        ret = parse_prog_number(av, &j, ac, &tmp);
        if (ret == 84)
            return 84;
        if (ret)
            continue;
        ret = parse_prog_adress(av, &j, ac, &tmp);
        if (ret == 84)
            return 84;
        if (ret)
            continue;
        tmp.path = my_strdup(av[j]);
        break;
    }
    *i = j;
    return check_file(args, &tmp);
}