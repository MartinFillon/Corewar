/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_
    #include "op.h"
    #define ERROR 84
    #define SUCCESS 0

/* PARSER */
int launch_parser(header_t *header, char const *filepath);

/* ERROR HANDLING */
// BASE
int check_args(int argc);

/* CONVERSION */
void write_file(header_t *header, const char *filepath);

#endif /* !COREWAR_H_ */
