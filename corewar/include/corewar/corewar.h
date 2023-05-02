/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include <stddef.h>

typedef struct arguments_s arguments_t;

int parse_cycles(char **av, arguments_t *args);
int parse_prog(char **av, int ac, arguments_t *args, int *i);
#endif /* !COREWAR_H_ */
