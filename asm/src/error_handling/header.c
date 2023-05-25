/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** header
*/

#include "my_str.h"
#include "my_stdio.h"

#include "asm/asm.h"

int check_header_size(header_t *header)
{
    if (my_strlen(header->prog_name) > PROG_NAME_LENGTH) {
        my_dprintf(2, "header: Champion name too long\n");
        return ERROR;
    }
    if (my_strlen(header->comment) > COMMENT_LENGTH) {
        my_dprintf(2, "header: Champion comment too long\n");
        return ERROR;
    }
    return SUCCESS;
}

void cleanup_quotes(str_t **str)
{
    if (str_find((*str), STR("\""), 0) != -1){
        str_slice(str, 0, str_find((*str), STR("\""), 0));
    }
}
