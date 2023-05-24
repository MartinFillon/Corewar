/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    #include "corewar.h"


typedef union {
    char reg;
    short ind;
    int dir;
} arg_types_t;

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

// GETTERS
int get_arg(arg_types_t *arg, u_char *memory, int *pc, u_char arg_type);
void get_arg_types(u_char *memory, int *pc, u_char *arg_types);
arg_types_t get_direct(u_char *mememory, int memory_index);
arg_types_t get_indirect(u_char *memory, int memory_index);
int convert_index(u_char type, program_t *p, int st, vm_t *vm);
int convert_index_long(u_char type, program_t *p, int st, vm_t *vm);

//Writers
void write_int(u_char *memory, int index, int content);


#endif /* !INSTRUCTIONS_H_ */
