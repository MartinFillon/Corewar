/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    #include <sys/types.h>

    #include "my_vec.h"

    #include "asm/asm.h"

typedef struct cmd_s {
    u_char command;
    u_char nb_param;
    int arg_type[4];
    union params {
        u_char reg;
        short index;
        int value;
    } param[4];
} cmd_t;

extern const op_name_t OP_NAME[];

VEC_DEF(cmd_t, cmd);

#endif /* !INSTRUCTIONS_H_ */
