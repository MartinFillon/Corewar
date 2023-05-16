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

int get_arg(cmd_t *cmd, size_t arg_type, int fd)
{
    if (read(fd, &cmd->param[cmd->nb_param], arg_type) < 0)
        return 1;

    cmd->nb_param++;
    return 0;
}

bool arg_match(int arg_type, cmd_t *cmd, int fd)
{
    switch (arg_type) {
        case 0b01: return get_arg(cmd, sizeof(char), fd);
        case 0b10: return get_arg(cmd, DIR_SIZE, fd);
        case 0b11: return get_arg(cmd, IND_SIZE, fd);
    }

    return false;
}

int parse_arguments(cmd_t *cmd, u_char coding_byte, int fd)
{
    int arg_type = 0b0;

    for (int i = 3; i >= 0; i--) {
        arg_type = get_bits(coding_byte, i * 2, 2);
        if (arg_type == 0b0)
            continue;
        if (arg_match(arg_type, cmd, fd))
            return 1;
    }
    return 0;
}

int handle_special(cmd_t *cmd, int fd)
{
    switch (cmd->command) {
        case 0x01: return get_arg(cmd, DIR_SIZE, fd);
        case 0x09: return get_arg(cmd, IND_SIZE, fd);
        case 0x0c: return get_arg(cmd, IND_SIZE, fd);
        case 0x0f: return get_arg(cmd, IND_SIZE, fd);
    }

    return 0;
}

int parse_instruction(vec_cmd_t **commands, char c, int fd)
{
    cmd_t cmd = {0};
    char coding_byte = 0;

    cmd.command = c;
    if (c == 0x1 || c == 0x9 || c == 0xc || c == 0xf) {
        if (handle_special(&cmd, fd))
            return 1;
        vec_pushback(commands, &cmd);
        return 0;
    }
    if (read(fd, &coding_byte, sizeof(char)) < 0)
        return 1;
    parse_arguments(&cmd, coding_byte, fd);
    for (size_t j = 0; j < 16; j++) {
        if (cmd.command == OP_NAME[j].hex) {
            dprintf(2, "%s\n", OP_NAME[j].name);
            break;
        }
    }
    vec_pushback(commands, &cmd);
    return 0;
}

int read_program(prog_t *prog)
{
    int fd = open(prog->path, O_RDONLY);
    header_t header;
    vec_cmd_t *commands = vec_create(100, sizeof(cmd_t));
    char c;

    if (read(fd, &header, sizeof(header_t)) < 0)
        return (ERROR);
    for (int i = 0; i < swap_endian(header.prog_size); i++) {
        if (read(fd, &c, sizeof(char)) < 0)
            return ERROR;
        if (parse_instruction(&commands, c, fd))
            return ERROR;
    }
    close(fd);
    for (size_t i = 0; i < commands->size; i++) {
        for (size_t j = 0; j < 16; j++) {
            if (commands->data[i].command == OP_NAME[j].hex) {
                dprintf(2, "%s\n", OP_NAME[j].name);
                break;
            }
        }
    }
    return (0);
}
