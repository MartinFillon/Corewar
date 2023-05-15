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

#include "my_vec.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"

static void free_arguments(arguments_t *args)
{
    for (size_t i = 0; i < args->programs->size; i++) {
        free(args->programs->data[i].path);
        close(args->programs->data[i].fd);
    }
    free(args->programs);
}

int main(int ac, char **av)
{
    arguments_t args;

    if (ac < MIN_AC || (ac > MIN_AC && parse_cycles(av, &args)))
        return ERROR;

    args.programs = vec_create(100, sizeof(prog_t));

    for (int i = START_AV; i < ac; i++)
        if (parse_prog(av, ac, &args, &i) == false)
            return ERROR;

    free_arguments(&args);
    return SUCCESS;
}
