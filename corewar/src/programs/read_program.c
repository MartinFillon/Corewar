/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** read_program
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "corewar/op.h"
#include "my_str.h"

#include "corewar/corewar.h"

int read_program(prog_t *prog)
{
    int fd = open(prog->path, O_RDONLY);
    header_t header;
    op_t op;
    
    if (read(fd, &header, sizeof(header_t)) < 0)
        return (ERROR);
    if (read(fd, &op, sizeof(op_t)) < 0)
        return (ERROR);
    write(1, &op, sizeof(op_t));
    return (0);
}
