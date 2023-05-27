/*
** EPITECH PROJECT, 2022
** test123
** File description:
** dump the arena
*/

#include <stdio.h>

#include "my_stdio.h"

#include "corewar/corewar.h"

static void print_hex_value(vm_t *vm, size_t i)
{
    if (vm->arena[i] == 0x0) {
        my_putstr("00 ");
    } else {
        if (vm->arena[i] <= 0xF)
            my_putstr("0");

        my_printf("%B ", (unsigned long){vm->arena[i]}, 16);
    }
}

static void print_row(size_t i)
{
    my_printf("%B ", i, 16);

    if (i < 0x10)
        my_putstr(" ");
    if (i < 0x100)
        my_putstr(" ");
    if (i < 0x1000)
        my_putstr(" ");

    my_putstr(": ");
}

void dump_memory(vm_t *vm)
{
    for (size_t i = 0; i < MEM_SIZE; ++i) {
        if (i % 32 == 0)
            print_row(i);

        print_hex_value(vm, i);

        if (i % 32 == 31)
            my_putchar('\n');
    }
}
