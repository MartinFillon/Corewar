/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_

    #include <stdbool.h>

    #include "corewar/corewar.h"

typedef struct indirect_s {
    short ind;
    int value;
} indirect_t;

typedef struct ind_state_s {
    u_char *memory;
    int start;
    bool _idx_mod;
} ind_state_t;

typedef union {
    char reg;
    int dir;
    indirect_t ind;
} arg_types_t;

typedef struct {
    arg_types_t data;
    bool is_index;
    u_char arg_type;
} argument_t;

typedef arg_types_t (*get_arg_t)(u_char *, int *);

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
void get_arg(argument_t *arg, u_char *memory, int *pc);
void get_arg_types(u_char *memory, int *pc, argument_t *arg_types);
arg_types_t get_dir(u_char *memory, int *memory_index);
arg_types_t get_ind(u_char *memory, int *memory_index);
arg_types_t get_reg(u_char *memory, int *memory_index);
int convert_index(u_char type, program_t *p, int st, vm_t *vm);
int convert_index_long(u_char type, program_t *p, int st, vm_t *vm);
void get_ind_value(
    arg_types_t *indirect, u_char *memory, int start, bool _idx_mod
);
int get_value(argument_t *args, program_t *p, ind_state_t *ind_state);
void debug_args(argument_t *args);

//Writers
void write_int(u_char *memory, int index, int content);
int read_int(u_char *memory, int index);


#endif /* !INSTRUCTIONS_H_ */
