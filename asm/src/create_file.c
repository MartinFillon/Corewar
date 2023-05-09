/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** create_file
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "my_str.h"
#include "my_stdio.h"

#include "corewar/op.h"
#include "asm/asm.h"

str_t *convert_file(char const *filepath)
{
    str_t *new_file = str_create(filepath);

    if (str_endswith(new_file, STR(".s")) == 0){
        my_dprintf(2, "Error: File must be a .s\n");
        return NULL;
    }

    str_replace(&new_file, STR(".s"), STR(".cor"));
    return new_file;
}

void write_file(header_t *header, char const *filepath, str_t *buffer)
{
    str_t *new_file = convert_file(filepath);
    int fd = 0;

    if (new_file == NULL){
        return;
    }

    fd = open(new_file->data, O_CREAT | O_WRONLY, 0644);
    if (fd < 0){
        my_dprintf(2, "Error: Can't open file\n");
        return;
    }

    write(fd, header, sizeof(header_t));
    write(fd, buffer->data, buffer->length);
    free(new_file);
    close(fd);
}
