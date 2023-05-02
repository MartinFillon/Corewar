/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parser
*/

#include "my_cstr.h"
#include "my_stdio.h"
#include "my_str.h"

#include "asm/asm.h"
#include "corewar/op.h"

static const int LENGTH_NAME = 7;
static const int LENGTH_COMMENT = 10;

static void fill_struct(vec_str_t *champ, header_t *header)
{
    for (size_t i = 0; i < champ->size; ++i) {
        if (str_startswith(champ->data[i], STR(".name"))) {
            my_strcpy(header->prog_name, champ->data[i]->data + LENGTH_NAME);
        }
        if (str_startswith(champ->data[i], STR(".comment"))) {
            my_strcpy(header->comment, champ->data[i]->data + LENGTH_COMMENT);
        }
    }
    for (int i = 0; header->prog_name[i] != '\0'; i++)
        if (header->prog_name[i] == '"')
            header->prog_name[i] = '\0';
    for (int i = 0; header->comment[i] != '\0'; i++)
        if (header->comment[i] == '"')
            header->comment[i] = '\0';
    my_printf("name = %s\n", header->prog_name);
    my_printf("comment = %s\n", header->comment);
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 0;
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
    fill_struct(champ, header);
    parse_body(champ);
    return content;
}

int launch_parser(header_t *header, char const *filepath)
{
    str_t *champ = NULL;

    champ = parse_header(filepath, header);
    if (champ == NULL){
        return ERROR;
    }
    return SUCCESS;
}
