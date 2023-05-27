/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** array
*/

#include "my_map.h"
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

#include "../include/json.h"

static void json_init_array(json_state_t *st)
{
    json_elem_t *elem = malloc(sizeof(json_elem_t));

    elem->type = JSON_ARRAY;
    elem->value.array = vec_create(50, sizeof(void *));
    append_value(st, elem);

    st->self = elem;

    str_clear(&st->parent);
}

int parse_array(json_state_t *st)
{
    json_elem_t *parent = st->self;

    json_init_array(st);
    if (get_char(st) == '[')
        next_char(st);
    while (get_char(st) != ']') {
        if (skip_whitespace(st) == -1)
            return -1;
        if (parse_value(st) == -1)
            return -1;
        if (skip_whitespace(st) == -1)
            return -1;
        if (get_char(st) == ',')
            next_char(st);
    }
    next_char(st);
    if (parent != NULL)
        st->self = parent;
    return get_char(st);
}
