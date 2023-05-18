/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** check valid progs
*/

#include <fcntl.h>
#include <unistd.h>

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "corewar/corewar.h"

static bool find_conflicting_number(vm_t *vm, prog_t *prog)
{
    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (prog->number == vm->programs->data[i].number) {
            my_dprintf(2, "Error: duplicate program number\n");
            return true;
        }
    }

    return false;
}

static bool find_conflicting_address(vm_t *vm, prog_t *prog)
{
    for (size_t i = 0; i < vm->programs->size; ++i) {
        if (prog->address == vm->programs->data[i].address) {
            my_dprintf(2, "Error: duplicate program address\n");
            return true;
        }
    }

    return false;
}

bool check_valid_prog(vm_t *vm, prog_t *prog, char const *path)
{
    if (prog->number != -1 && find_conflicting_number(vm, prog))
        return false;

    if (prog->address != -1 && find_conflicting_address(vm, prog))
        return false;

    if (my_strendwith(path, ".cor") == false) {
        my_dprintf(2, "Error: %s is not a .cor file\n", path);
        return false;
    }

    return true;
}
