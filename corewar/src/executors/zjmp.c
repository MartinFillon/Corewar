/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** zjmp
*/

#include "corewar/corewar.h"
#include "corewar/op.h"

int exec_zjmp(program_t *p, char *memory, int *pc)
{
    int arg = 0;
    int address = *pc;

    get_arg(&arg, memory, pc, T_DIR);
    if (p->carry == 1)
        *pc = (address + (arg % IDX_MOD)) % MEM_SIZE;
    return 0;
}
