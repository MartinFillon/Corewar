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

int nb_char_to_skip(str_t *line)
{
    for (size_t i = 0; line->data[i] != '\0'; i++) {
        if (line->data[i] == '"')
            return i + 1;
    }
    return ERROR;
}

static void cleanup_header(header_t *header)
{
    for (int i = 0; header->prog_name[i] != '\0'; i++){
        if (header->prog_name[i] == '"')
            header->prog_name[i] = 0;
    }
    for (int i = 0; header->comment[i] != '\0'; i++){
        if (header->comment[i] == '"')
            header->comment[i] = 0;
    }
}

static void fill_struct(vec_str_t *champ, header_t *header)
{
    my_memset(header->prog_name, 0, PROG_NAME_LENGTH + 1);
    my_memset(header->comment, 0, COMMENT_LENGTH + 1);

    for (size_t i = 0; i < champ->size; ++i) {
        if (str_startswith(champ->data[i], STR(".name"))) {
            my_strcpy(header->prog_name, champ->data[i]->data
            + nb_char_to_skip(champ->data[i]));
        }
        if (str_startswith(champ->data[i], STR(".comment"))) {
            my_strcpy(header->comment, champ->data[i]->data
            + nb_char_to_skip(champ->data[i]));
        }
    }
    cleanup_header(header);
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
