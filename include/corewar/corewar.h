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
    #define SUCESS 0

void launch_parser(int ac, char **argv);
void write_file(header_t *header, const char *filepath);

#endif /* !COREWAR_H_ */
