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

static bool read_program(program_t *program, int fd)
{
    if (read(fd, &program->header, sizeof(header_t)) != sizeof(header_t)) {
        my_dprintf(2, "Error: failed to read header\n");
        return false;
    }
    if (swap_endian(program->header.magic) != COREWAR_EXEC_MAGIC) {
        my_dprintf(2, "Error: wrong magic number\n");
        return false;
    }
    int prog_size = swap_endian(program->header.prog_size);
    program->body = malloc(sizeof(char) * prog_size);
    if (program->body == NULL) {
        my_dprintf(2, "Error: malloc failed\n");
        return false;
    }
    if (read(fd, program->body, prog_size) != prog_size) {
        my_dprintf(2, "Error: failed to read body\n");
        return false;
    }
    return true;
}

bool check_and_read_prog(vm_t *vm, prog_t *prog, char const *path)
{
    if (my_strendwith(path, ".cor") == false) {
        my_dprintf(2, "Error: %s is not a .cor file\n", path);
        return false;
    }

    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        my_dprintf(2, "Error: Can't read .cor file %s\n", path);
        return false;
    }
    if (read_program(&prog->program, fd) == false) {
        close(fd);
        return false;
    }
    vec_pushback(&vm->programs, prog);
    close(fd);
    return true;
}
