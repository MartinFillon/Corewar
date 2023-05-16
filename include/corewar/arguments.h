/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** arguments
*/

#ifndef ARGUMENTS_H_
    #define ARGUMENTS_H_

    #include <stddef.h>
    #include "corewar/op.h"
    #include "my_vec.h"
    #include "my_str.h"

typedef struct prog_s {
    size_t adress;
    size_t number;
    char *path;
    int fd;
    header_t header;
    str_t *instructions;
    int *instructions_adress;
} prog_t;

VEC_DEF(prog_t, prog);

typedef struct arguments_s {
    size_t nbr_cycles;
    vec_prog_t *programs;
} arguments_t;

#endif /* !ARGUMENTS_H_ */
