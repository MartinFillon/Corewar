/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parser
*/

#include "my_cstr.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "asm/asm.h"
#include "corewar/op.h"

static int cleanup_header(header_t *header)
{
    char *comment_temp = my_strchr(header->comment, '"');
    char *name_temp = my_strchr(header->prog_name, '"');

    if (name_temp == NULL || comment_temp == NULL)
        return ERROR;
    *comment_temp = '\0';
    *name_temp = '\0';
    return SUCCESS;
}

static int fill_header(vec_str_t *champ, header_t *header)
{
    int quote_idx = 0;

    for (size_t i = 0; i < champ->size; ++i) {
        if (str_startswith(champ->data[i], STR(NAME_CMD_STRING)) &&
        (quote_idx = str_find(champ->data[i], STR("\""), 0)) != -1)
            my_strcpy(header->prog_name, champ->data[i]->data
            + quote_idx + 1);
        if (str_startswith(champ->data[i], STR(COMMENT_CMD_STRING )) &&
        (quote_idx = str_find(champ->data[i], STR("\""), 0)) != -1)
            my_strcpy(header->comment, champ->data[i]->data
            + quote_idx + 1);
    }
    if (header->comment[0] == '\0' || header->prog_name[0] == '\0' ||
    cleanup_header(header) == ERROR)
        return ERROR;
    return SUCCESS;
}

static str_t *parse_header(char const *champ_path, header_t *header)
{
    str_t *content = read_file(champ_path);

    if (content == NULL)
        return NULL;

    vec_str_t *champ = str_split(content, STR("\n"));
    for (size_t i = 0; i < champ->size; i++) {
        str_ltrim(&champ->data[i], '\t');
        str_ltrim(&champ->data[i], ' ');
    }
    if (fill_header(champ, header) == ERROR)
        return NULL;
    if (parse_body(champ, champ_path, header) == ERROR) {
        vec_free(champ);
        return NULL;
    }
    vec_free(champ);
    return content;
}

int launch_parser(header_t *header, char const *filepath)
{
    str_t *champ = NULL;

    champ = parse_header(filepath, header);
    if (champ == NULL) {
        return ERROR;
    }
    free(champ);

    header->magic = convert_big_endian(COREWAR_EXEC_MAGIC);
    return SUCCESS;
}
