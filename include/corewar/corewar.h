/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_
    #include <sys/types.h>
    #include "my_vec.h"
    #define ERROR 84
    #define SUCCESS 0
    #include "corewar/arguments.h"

int parse_cycles(char **av, arguments_t *args);
int parse_prog(char **av, int ac, arguments_t *args, int *i);
int read_program(prog_t *prog);
#endif /* !COREWAR_H_ */
