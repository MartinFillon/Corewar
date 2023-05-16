/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read_program
*/

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "my_btree.h"
#include "my_stdio.h"

#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

#include "asm/asm.h"
#include "corewar/corewar.h"
#include "corewar/instructions.h"
#include "corewar/op.h"

int swap_endian(int val)
{
    return (
        (val & 0x000000ff) << 24 |
        (val & 0x0000ff00) << 8 |
        (val & 0x00ff0000) >> 8 |
        (val & 0xff000000) >> 24
    );
}

u_char get_bits(u_char byte, int start, int count)
{
    return ((1 << count) - 1) & (byte >> start);
}

int read_program(prog_t *prog)
{
    char c;
    prog->instructions = str_create("");

    if (read(prog->fd, &prog->header, sizeof(header_t)) < 0)
        return (ERROR);
    for (int i = 0; i < swap_endian(prog->header.prog_size); i++) {
        if (read(prog->fd, &c, sizeof(char)) < 0)
            return ERROR;
        str_cadd(&prog->instructions, c);
    }
    close(prog->fd);
    return (0);
}
