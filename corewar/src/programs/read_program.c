/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read_program
*/

#include <fcntl.h>
#include <unistd.h>

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "corewar/corewar.h"
#include "corewar/op.h"

static bool read_header(program_t *p, int fd)
{
    if (read(fd, &p->header, sizeof(header_t)) != sizeof(header_t)) {
        my_dprintf(2, "Error: failed to read header\n");
        return false;
    }

    p->header.magic = swap_endian(p->header.magic);
    p->header.prog_size = swap_endian(p->header.prog_size);

    if (p->header.magic != COREWAR_EXEC_MAGIC) {
        my_dprintf(2, "Error: wrong magic number\n");
        return false;
    }
    if (p->header.prog_size > MEM_SIZE) {
        my_dprintf(2, "Error: program size is bigger than the arena\n");
        return false;
    }
    return true;
}

static bool read_program(program_t *p, int fd)
{
    if (read_header(p, fd) == false)
        return false;

    p->body = malloc(sizeof(char) * p->header.prog_size);

    if (p->body == NULL) {
        my_dprintf(2, "Error: malloc failed\n");
        return false;
    }
    if (read(fd, p->body, p->header.prog_size) != p->header.prog_size) {
        free(p->body);
        my_dprintf(2, "Error: failed to read body\n");
        return false;
    }
    return true;
}

bool check_and_read_prog(vm_t *vm, prog_t *prog, char const *path)
{
    if (check_valid_prog(vm, prog, path) == false)
        return false;

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
