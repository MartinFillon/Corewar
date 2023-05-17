/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "corewar/arguments.h"
#include "corewar/corewar.h"
#include "corewar/op.h"

static bool parse_argv(int ac, char const *const *av, vm_t *vm)
{
    if (ac < MIN_AC || (ac > MIN_AC && parse_cycles(av, vm) == false)) {
        my_dprintf(2, "Error: invalid args, %d\n", ac);
        return false;
    }

    for (int i = START_AV; i < ac; ++i)
        if (parse_prog(av, ac, vm, &i) == false)
            return false;

    return true;
}

void print_progs(vec_prog_t *progs)
{
    for (size_t i = 0; i < progs->size; ++i) {
        program_t *prog = &progs->data[i].program;
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

int main(int ac, char const *const *av)
{
    vm_t vm = init_vm();

    if (parse_argv(ac, av, &vm) == false) {
        return ERROR;
    }

    print_progs(vm.programs);

    free_vm(&vm);
    return SUCCESS;
}
