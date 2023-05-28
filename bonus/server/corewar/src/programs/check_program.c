/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** check valid progs
*/

#include "stdio.h"

#include "corewar/corewar.h"

static bool find_conflicting_number(vm_t *vm, prog_t *prog)
{
    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (prog->number == vm->programs->data[i].number) {
            dprintf(2, "Error: double definition of prog_number.\n");
            return true;
        }
    }

    return false;
}

bool check_valid_prog(vm_t *vm, prog_t *prog, char const *path)
{
    if (prog->number != -1 && find_conflicting_number(vm, prog))
        return false;

    if (my_strendwith(path, ".cor") == false) {
        dprintf(2, "Error: %s is not a .cor file\n", path);
        return false;
    }

    return true;
}

bool check_progs_sizes(vm_t *vm)
{
    long allowed_size = MEM_SIZE / vm->programs->size;

    for (size_t i = 0; i < vm->programs->size; ++i) {
        prog_t *p = &vm->programs->data[i];

        if (p->program.header.prog_size > allowed_size) {
            dprintf(2, "Error: champion size is too big (%s)\n", p->path);
            return false;
        }
    }

    return true;
}
