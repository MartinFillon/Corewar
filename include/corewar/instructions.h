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

typedef struct command_s {
    u_char command;
    u_char nb_param;
    u_char params[4];
    union {
        u_int value;
        u_char reg;
        u_short index;
    } param[4];
} cmd_t;

extern const op_name_t OP_NAME[];

VEC_DEF(cmd_t, cmd);

#endif /* !INSTRUCTIONS_H_ */
