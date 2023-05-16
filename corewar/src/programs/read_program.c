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
    if (read(prog->fd, &prog->program.header, sizeof(header_t)) < 0) {
        dprintf(2, "Error: read failed header\n");
        return ERROR;
    }
    prog->program.instructions = malloc(sizeof(char) * swap_endian(prog->program.header.prog_size));
    if (read(prog->fd, prog->program.instructions, swap_endian(prog->program.header.prog_size)) < 0) {
        dprintf(2, "Error: read failed instructions\n");
        return ERROR;
    }
    close(prog->fd);
    prog->program.registers = malloc(REG_SIZE * REG_NUMBER);
    prog->program.pc = 0;
    return (0);
}
