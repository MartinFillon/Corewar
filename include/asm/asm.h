/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#ifndef ASM_H_
    #define ASM_H_
    #include "corewar/op.h"
    #define ERROR 84
    #define SUCCESS 0

/* PARSER */
int launch_parser(header_t *header, char const *filepath);

/* ERROR HANDLING */
// BASE
int check_args(int argc);

/* CONVERSION */
void write_file(header_t *header, const char *filepath);

#endif /* !ASM_H_ */
