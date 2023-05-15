/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_vec.h"

#include "corewar/corewar.h"

int main(int ac, char **av)
{
    arguments_t args;

    if (ac < 2)
        return ERROR;
    if (parse_cycles(av, &args))
        return ERROR;
    args.programs = vec_create(100, sizeof(prog_t));
    for (int i = 3; i < ac; i++) {
        if (parse_prog(av, ac, &args, &i) == ERROR)
            return ERROR;
    }
    for (size_t i = 0; i < args.programs->size; i++)
        if (read_program(&args.programs->data[i]) == ERROR)
            return ERROR;
    for (size_t i = 0; i < args.programs->size; i++)
        free(args.programs->data[i].path);
    free(args.programs);
    return SUCCESS;
}
