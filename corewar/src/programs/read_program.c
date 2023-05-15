/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read_program
*/

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "my_btree.h"
#include "my_stdio.h"

#include "asm/asm.h"
#include "my_str.h"
#include "my_vec.h"

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

int get_arg(cmd_t *cmd, size_t arg_type, int fd)
{
    static int i = 0;

    if (read(fd, &cmd->params[i], arg_type) < 0)
        return (1);
    i++;
    return (0);
}

int parse_arguments(cmd_t *cmd, u_char coding_byte, int fd)
{
    int arg_type;
    (void)cmd;
    (void)fd;
    dprintf(2, "%d\n", coding_byte);

    for (int i = 3; i >= 0; i--) {
        arg_type = get_bits(coding_byte, i * 2, 2);
        dprintf(2, "%d\n", arg_type);
        if (arg_type == 0b0)
            continue;
        if (arg_type == 0b01)
            if (get_arg(cmd, sizeof(char), fd))
                return (1);
        if (arg_type == 0b10)
            if (get_arg(cmd, DIR_SIZE, fd))
                return (1);
        if (arg_type == 0b11)
            if (get_arg(cmd, IND_SIZE, fd))
                return (1);
    }
    return 0;
}

int parse_instruction(vec_cmd_t **commands, char c, int fd)
{
    cmd_t cmd;
    char coding_byte;

    cmd.command = c;
    if (read(fd, &coding_byte, sizeof(char)) < 0)
        return 1;
    parse_arguments(&cmd, coding_byte, fd);
    vec_pushback(commands, &cmd);
    exit(0);
    return 0;
}

int read_program(prog_t *prog)
{
    int fd = open(prog->path, O_RDONLY);
    header_t header;
    char c;
    vec_cmd_t *commands = vec_create(100, sizeof(cmd_t));

    if (read(fd, &header, sizeof(header_t)) < 0)
        return (ERROR);
    // write(1, &header, sizeof(header_t));
    for (int i = 0; i < swap_endian(header.prog_size); i++) {
        if (read(fd, &c, sizeof(char)) < 0)
            return ERROR;
        if (parse_instruction(&commands, c, fd))
            return ERROR;
    }
    close(fd);
    // dprintf(1, "%s\n", commands->data);
    return (0);
}
