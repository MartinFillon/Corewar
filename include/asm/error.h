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


int check_sti(size_t instruction, vec_str_t *params);
int check_st(size_t instruction, vec_str_t *params);
int check_load_base(size_t instruction, vec_str_t *params);
int check_load_further(size_t instruction, vec_str_t *params);
int check_arithm(size_t instruction, vec_str_t *params);
int check_bitwise(size_t instruction, vec_str_t *params);
int check_fork(size_t instruction, vec_str_t *params);
int check_live(size_t instruction, vec_str_t *params);
int check_zjmp(size_t instruction, vec_str_t *params);
int check_aff(size_t instruction, vec_str_t *params);

#endif /* !ERROR_H_ */
