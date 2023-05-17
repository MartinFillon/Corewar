/*
** EPITECH PROJECT, 2022
** test123
** File description:
** program utils
*/

#include "my_stdio.h"

#include "corewar/corewar.h"

void print_progs(vec_prog_t *progs)
{
    program_t *prog = NULL;

    for (size_t i = 0; i < progs->size; ++i) {
        prog = &progs->data[i].program;
        my_printf("progs[%d] = {\n\taddress: %d\n", i, progs->data[i].address);
        my_printf("\tnumber: %d\n\tprogram: {\n", progs->data[i].number);
        my_printf("\t\tcarry: %d\n", progs->data[i].program.carry);
        my_printf("\t\tpc: %d\n\t\tregisters: [ ", progs->data[i].program.pc);
        for (int j = 0; j < REG_NUMBER; j++)
            my_printf(
                "%d%s", prog->registers[j], (j != REG_NUMBER - 1) ? ", " : ""
            );
        my_printf(" ]\n\t\theader: {\n");
        my_printf("\t\t\tprog_name: %s\n", prog->header.prog_name);
        my_printf("\t\t\tcomment: %s\n", prog->header.comment);
        my_printf("\t\t\tprog_size: %d\n", swap_endian(prog->header.prog_size));
        my_printf("\t\t\tmagic: %b\n", swap_endian(prog->header.magic), 16);
        my_printf("\t\t}\n\t}\n}\n");
    }
}
