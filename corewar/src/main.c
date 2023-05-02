/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "my_vec.h"

int main(int ac, char **av)
{
    arguments_t args;

    if (ac < 2)
        return 84;
    if (parse_cycles(av, &args))
        return 84;
    args.programs = vec_create(100, sizeof(prog_t));
    for (int i = 3; i < ac; i++) {
        if (parse_prog(av, ac, &args, &i) == 84)
            return 84;
    }
    for (size_t i = 0; i < args.programs->size; i++)
        free(args.programs->data[i].path);
    free(args.programs);
    return 0;
}
