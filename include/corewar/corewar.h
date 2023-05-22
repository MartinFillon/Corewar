/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include <stdbool.h>
    #include <sys/types.h>

    #include "my_vec.h"

    #define ERROR 84
    #define SUCCESS 0

    #define MIN_AC (2)
    #define START_AV (1)

    #define MAX_PROG_AV (5)

    #define UNUSED __attribute__((unused))

    #define HELP_MESSAGE                                                       \
        "USAGE\n"                                                              \
        "\t%s [-dump nbr_cycle] [[-n prog_number] [-a load_address] "          \
        "prog_name] "                                                          \
        "...\n"

    #include "corewar/arguments.h"


// PARSING
bool check_valid_prog(vm_t *vm, prog_t *prog, char const *path);
bool check_and_read_prog(vm_t *vm, prog_t *prog, char const *path);
bool parse_cycles(char const *const *av, vm_t *vm);
bool parse_prog(char const *const *av, int ac, vm_t *vm, int *i);
bool parse_argv(int ac, char const *const *av, vm_t *vm);
bool show_help(int ac, char const *const *av);
bool check_progs_sizes(vm_t *vm);


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

// GETTERS
int get_arg(int *arg, char *memory, int *pc, u_char arg_type);
int get_direct(char *mememory, int memory_index);
void get_arg_types(char *memory, int memory_index, u_char *arg_types);
int get_indirect(char *memory, int memory_index, int index);

//Writers
void write_int(char *memory, int index, int content);

#endif /* !COREWAR_H_ */
