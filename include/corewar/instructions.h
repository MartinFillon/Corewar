/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    #include "corewar.h"

int exec_sub(program_t *p, char *memory, int *pc);
int exec_ld(program_t *p, char *memory, int *pc);
int exec_and(program_t *p, char *memory, int *pc);
int exec_live(program_t *p, char *memory, int *pc);
int exec_st(program_t *p, char *memory, int *pc);
int exec_add(program_t *p, char *memory, int *pc);

#endif /* !INSTRUCTIONS_H_ */
