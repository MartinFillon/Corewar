/*
** EPITECH PROJECT, 2022
** my_stdio
** File description:
** read file
*/

#include <fcntl.h>
#include <unistd.h>

#include "my_stdlib.h"
#include "my_str.h"

str_t *read_file(char const *file_path)
{
    int fd = open(file_path, O_RDONLY);
    str_t *content = str_create("");
    size_t r_size = 0;
    char buffer[2048];

    if (content == NULL)
        return NULL;
    if (fd < 0) {
        free(content);
        return NULL;
    }
    while ((r_size = read(fd, buffer, 2048)) > 0)
        str_nadd(&content, buffer, r_size);
    close(fd);

    return content;
}
