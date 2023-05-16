/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include <sys/types.h>
    #include <stdbool.h>

    #include "my_vec.h"

    #define ERROR 84
    #define SUCCESS 0

    #include "corewar/arguments.h"


typedef unsigned char u_char;

int read_program(prog_t *prog);
bool parse_cycles(char **av, arguments_t *args);
bool parse_prog(char **av, int ac, arguments_t *args, int *i);

#endif /* !COREWAR_H_ */
