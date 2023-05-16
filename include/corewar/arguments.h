/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** arguments
*/

#ifndef ARGUMENTS_H_
    #define ARGUMENTS_H_

    #include <stdbool.h>
    #include <stddef.h>
    #include "corewar/op.h"
    #include "my_vec.h"
    #include "my_str.h"

typedef struct program_s {
    header_t header;
    char *instructions;
    int *registers;
    int pc;
    bool carry;
} program_t;

typedef struct prog_s {
    size_t adress;
    size_t number;
    char *path;
    int fd;
    program_t program;
} prog_t;

VEC_DEF(prog_t, prog);

typedef struct arguments_s {
    size_t nbr_cycles;
    vec_prog_t *programs;
} arguments_t;

#endif /* !ARGUMENTS_H_ */
