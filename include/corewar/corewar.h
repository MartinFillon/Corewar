/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include <sys/types.h>
    #include <stdbool.h>

    #include "my_vec.h"

    #define ERROR 84
    #define SUCCESS 0

    #define MIN_AC (2)
    #define START_AV (1)

    #define MAX_PROG_AV (5)

    #define UNUSED __attribute__((unused))

    #include "corewar/arguments.h"


// PARSING
bool check_and_read_prog(vm_t *vm, prog_t *prog, char const *path);
bool parse_cycles(char const *const *av, vm_t *vm);
bool parse_prog(char const *const *av, int ac, vm_t *vm, int *i);


// UTILS
int swap_endian(int val);
u_char get_bits(u_char byte, int start, int count);


// VM
void free_vm(vm_t *vm);
vm_t init_vm(void);


// PROGRAM
prog_t init_prog(void);
void print_progs(vec_prog_t *progs);

// GETTERS
int get_direct(char *mememory, int memory_index);
void get_arg_types(char *memory, int memory_index, u_char *arg_types);
int get_indirect(char *memory, int memory_index);

#endif /* !COREWAR_H_ */
