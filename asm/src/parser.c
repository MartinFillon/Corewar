/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parser
*/

#include "my_cstr.h"
#include "my_stdio.h"
#include "my_str.h"

#include "corewar/corewar.h"
#include "corewar/op.h"
/*
static const char NAME[] = ".name";
static const size_t LENGTH_NAME = 5;
static const char COMMENT[] = ".comment";
static const size_t LENGTH_COMMENT = 8;
*/
static int error_from_path(int ac)
{
    if (ac != 2)
        return ERROR;
    return SUCESS;
}
/*
static void fill_static_name(str_t *str, header_t *header)
{
    int j = 0;
    for (int i = LENGTH_NAME + 2; str->data[i + 1] != '\0'; i++, j++) {
        header->prog_name[j] = str->data[i];
    }
    header->prog_name[j] = '\0';
}

static void fill_static_comment(str_t *str, header_t *header)
{
    int j = 0;
    for (int i = LENGTH_COMMENT + 2; str->data[i] != '\0'; i++, j++) {
        header->comment[j] = str->data[i];
    }
    header->comment[j] = '\0';
}*/

static void fill_struct(vec_str_t *champ, header_t *header)
{
    for (size_t i = 0; i < champ->size; ++i) {
        // fill_static_name(champ->data[i], header)

        // en gros le startswith retournait 1 quand la ligne etait vide
        // donc le header->prog_name etait overwrite par du vide
        if (str_startswith(champ->data[i], STR(".name"))) {
            my_strcpy(header->prog_name, champ->data[i]->data + 5);
        }

        /*
     if (!my_strncmp(COMMENT, champ->data[i]->data, LENGTH_COMMENT)) {
         fill_static_comment(champ->data[i], header);
     }*/
    }
    my_printf("[%s]\n", header->prog_name);
    // my_printf("%s\n", header->comment);
}

static str_t *parse_header(char *champ_path, header_t *header)
{
    str_t *content = read_file(champ_path);

    if (content == NULL)
        return NULL;
    vec_str_t *champ = str_split(content, STR("\n"));
    for (size_t i = 0; i < champ->size; i++) {
        str_ltrim(&champ->data[i], '\t');
    }
    fill_struct(champ, header);
    return content;
}

void launch_parser(int ac, char **argv)
{
    header_t header = {0};
    str_t *champ = NULL;

    if (error_from_path(ac) == ERROR ||
        (champ = parse_header(argv[1], &header)) == NULL)
        return;
}
