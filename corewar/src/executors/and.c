/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** and
*/

#include <sys/types.h>

#include "corewar/arguments.h"
#include "corewar/corewar.h"

int exec_and(program_t *p, char *memory, int *pc)
{
    u_char *arg_types =(u_char[4]){0};
    int reg = -1;
    int arg1 = 0;
    int arg2 = 0;
    int addr = *pc;

    get_arg_types(memory, ++*pc, arg_types);
    *pc += 1;
    if (arg_types[0] == 0b10) {
        arg1 = get_direct(memory, *pc);
        *pc += DIR_SIZE;
    } else if (arg_types[0] == 0b11) {
        arg1 = get_indirect(memory, *pc, addr);
        *pc += IND_SIZE;
    } else {
        *pc = addr;
        return 0;
    }
    if (arg_types[1] == 0b10) {
        arg2 = get_direct(memory, *pc);
        *pc += DIR_SIZE;
    } else if (arg_types[1] == 0b11) {
        arg2 = get_indirect(memory, *pc, addr);
        *pc += IND_SIZE;
    } else {
        *pc = addr;
        return 0;
    }
    reg = memory[*pc++];
    p->registers[reg - 1] = arg1 & arg2;
    return 0;
}
