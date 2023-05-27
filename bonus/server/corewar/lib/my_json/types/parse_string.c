/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** parse string
*/

#include "my_map.h"
#include "my_stdlib.h"
#include "my_str.h"

#include "../include/json.h"

static void add_escaped_char(json_state_t *st, str_t **value)
{
    switch (get_char(st)) {
        case -1:
            return;
        case 'n':
            str_cadd(value, '\n');
            break;
        case 't':
            str_cadd(value, '\t');
            break;
        case 'r':
            str_cadd(value, '\r');
            break;
        default:
            str_cadd(value, get_char(st));
    }
}

int parse_string(json_state_t *st)
{
    json_elem_t *elem = malloc(sizeof(json_elem_t));
    elem->value.string = str_create("");
    elem->type = JSON_STRING;

    if (get_char(st) == '"')
        next_char(st);
    while (get_char(st) != '"') {
        if (get_char(st) == '\\') {
            next_char(st);
            add_escaped_char(st, &elem->value.string);
        } else
            str_cadd(&elem->value.string, get_char(st));
        next_char(st);
    }
    next_char(st);
    append_value(st, elem);
    return get_char(st);
}
