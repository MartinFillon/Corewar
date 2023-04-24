/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** json parser
*/

#include "my_json.h"
#include "my_map.h"
#include "my_stdlib.h"
#include "my_stdio.h"
#include "my_str.h"

#include "./include/json.h"

json_elem_t *json_parse(str_t *data)
{
    json_state_t st = {
        .data = data,
        .self = NULL,
        .parent = STR(""),
        .data_idx = 0,
    };

    parse_value(&st);
    return st.self;
}

json_elem_t *json_from_file(char const *file_path)
{
    str_t *content = read_file(file_path);
    json_elem_t *json = NULL;

    if (content == NULL)
        return NULL;

    json = json_parse(content);
    free(content);
    return json;
}
