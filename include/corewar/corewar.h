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

    #define MIN_AC (2)
    #define START_AV (3)

    #define MAX_PROG_AV (5)

    #define UNUSED __attribute__((unused))

    #include "corewar/arguments.h"


// PARSING
int read_program(prog_t *prog);
bool parse_cycles(char **av, arguments_t *args);
bool parse_prog(char **av, int ac, arguments_t *args, int *i);


// UTILS
int swap_endian(int val);
u_char get_bits(u_char byte, int start, int count);


#endif /* !COREWAR_H_ */
