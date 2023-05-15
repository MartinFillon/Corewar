/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_
    #define ERROR (84)
    #define SUCCESS (0)

    #define MIN_AC (2)
    #define START_AV (3)

    #define MAX_PROG_AV (5)

    #include <stdbool.h>

    #include "corewar/arguments.h"

bool parse_cycles(char **av, arguments_t *args);
bool parse_prog(char **av, int ac, arguments_t *args, int *i);
#endif /* !COREWAR_H_ */
