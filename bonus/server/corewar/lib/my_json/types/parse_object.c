/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** parse object
*/

#include "my_cstr.h"
#include "my_map.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "../include/json.h"

static int parse_object_inner(json_state_t *st)
{
    switch (get_char(st)) {
        case '"': return parse_key(st);
        case ',': return next_char(st);
        case ':': return parse_value(st);
        default: return 0;
    }
}

static void init_object(json_state_t *st)
{
    json_elem_t *elem = malloc(sizeof(json_elem_t));

    elem->type = JSON_OBJECT;
    elem->value.object = map_create(JSON_OBJ_SIZE);

    append_value(st, elem);

    st->self = elem;
}

int parse_object(json_state_t *st)
{
    json_elem_t *parent = st->self;

    init_object(st);
    if (skip_whitespace(st) == -1)
        return -1;
    if (get_char(st) == '{')
        next_char(st);
    while (get_char(st) != '}') {
        if (skip_whitespace(st) == -1)
            return -1;
        if (parse_object_inner(st) == -1)
            return -1;
        if (skip_whitespace(st) == -1)
            return -1;
    }
    next_char(st);
    if (parent != NULL)
        st->self = parent;
    return get_char(st);
}
