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
bool check_valid_prog(vm_t *vm, prog_t *prog, char const *path);
bool check_and_read_prog(vm_t *vm, prog_t *prog, char const *path);
bool parse_cycles(char const *const *av, vm_t *vm, int *start_av_from);
bool parse_prog(char const *const *av, int ac, vm_t *vm, int *i);


// UTILS
int swap_endian(int val);
u_char get_bits(u_char byte, int start, int count);


// VM
vm_t init_vm(void);
void free_vm(vm_t *vm);
void print_vm(vm_t *vm);
bool start_vm(vm_t *vm);

bool load_programs(vm_t *vm);
void order_programs_by_number(vec_prog_t *programs);

void dump_memory(vm_t *vm);



// PROGRAM
prog_t init_prog(void);
void print_progs(vec_prog_t *progs);


#endif /* !COREWAR_H_ */
