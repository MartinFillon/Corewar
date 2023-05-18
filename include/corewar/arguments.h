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

    #include "my_vec.h"
    #include "my_str.h"

    #include "corewar/op.h"


typedef struct program_s {
    header_t header;
    char *body;
    int registers[REG_NUMBER];
    int pc;
    bool carry;
} program_t;

typedef struct prog_s {
    int address;
    int number;
    program_t program;
} prog_t;

VEC_DEF(prog_t, prog);

typedef struct vm_s {
    int cycle;
    int cycle_to_die;
    int nbr_cycles_to_dump;
    int nbr_live;
    int last_live;

    char memory[MEM_SIZE];
    vec_prog_t *programs;
} vm_t;

#endif /* !ARGUMENTS_H_ */
