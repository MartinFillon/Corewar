/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** error
*/

#ifndef ERROR_H_
    #define ERROR_H_
    #include "corewar/op.h"

int check_args(int argc, char **argv);

int swap_endian(int little);

void clean_comments(vec_str_t **words);

void cleanup_quotes(str_t **str);

int check_header_size(header_t *header);

#endif /* !ERROR_H_ */
