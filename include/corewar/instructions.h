/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    #include "corewar.h"

int exec_sub(vm_t *vm, program_t *p);
int exec_ld(vm_t *vm, program_t *p);
int exec_and(vm_t *vm, program_t *p);
int exec_or(vm_t *vm, program_t *p);
int exec_xor(vm_t *vm, program_t *p);
int exec_live(vm_t *vm, program_t *p);
int exec_st(vm_t *vm, program_t *p);
int exec_add(vm_t *vm, program_t *p);
int exec_zjmp(vm_t *vm, program_t *p);
int exec_ldi(vm_t *vm, program_t *p);
int exec_sti(vm_t *vm, program_t *p);
int exec_fork(vm_t *vm, program_t *p);
int exec_lld(vm_t *vm, program_t *p);
int exec_lldi(vm_t *vm, program_t *p);
int exec_lfork(vm_t *vm, program_t *p);
int exec_aff(vm_t *vm, program_t *p);

#endif /* !INSTRUCTIONS_H_ */
