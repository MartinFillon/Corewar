/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** create_file
*/

#include <fcntl.h>
#include <unistd.h>

#include "corewar/corewar.h"
#include "corewar/op.h"
#include "my_str.h"

str_t *convert_file(char const *filepath)
{
    str_t *new_file = str_create(filepath);
    str_t *original = str_create(".s");
    const str_t *final = str_create(".cor");

    if (str_endswith(new_file, original) == 0){
        write(2, "Error: File must be a .s\n", 26);
    }
    str_replace(&new_file, original, final);
    return new_file;
}

int write_file(header_t *header, char const *filepath)
{
    str_t *new_file = convert_file(filepath);
    int fd = open(new_file->data, O_CREAT | O_WRONLY, 0666);

    if (fd < 0){
        write(2, "Error: Can't open file\n", 24);
        return ERROR;
    } else {
        write(fd, header, sizeof(header_t));
    }
    close(fd);
    return SUCCESS;
}
