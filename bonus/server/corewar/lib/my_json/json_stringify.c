/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** json write
*/

#include <fcntl.h>

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

#include "./include/json.h"

static void stringify_data(str_t **buff, json_elem_t *elem);

static void stringify_object(str_t **buff, json_elem_t *elem)
{
    vec_str_t *keys = map_get_keys(elem->value.object);

    str_add(buff, "{");
    for (size_t i = 0; i < keys->size; i++) {
        str_fadd(buff, "\"%S\":", keys->data[i]);
        stringify_data(buff, map_get(elem->value.object, keys->data[i]));
        str_fadd(buff, "%s", (i != keys->size - 1) ? "," : "");
    }
    str_add(buff, "}");
    vec_free(keys);
}

static void stringify_array(str_t **buff, json_elem_t *elem)
{
    vec_json_t *array = elem->value.array;

    str_add(buff, "[");
    for (size_t i = 0; i < array->size; i++) {
        stringify_data(buff, array->data[i]);
        if (i != array->size - 1)
            str_add(buff, ",");
    }
    str_add(buff, "]");
}

static void stringify_data(str_t **buff, json_elem_t *elem)
{

    switch (elem->type) {
        case JSON_STRING: str_fadd(buff, "\"%S\"", elem->value.string); break;
        case JSON_LONG: str_fadd(buff, "%ld", (long)elem->value.number); break;
        case JSON_DOUBLE: str_fadd(buff, "%.2f", elem->value.number); break;
        case JSON_BOOLEAN:
            str_fadd(buff, "%s", elem->value.boolean ? "true" : "false");
            break;
        case JSON_ARRAY: stringify_array(buff, elem); break;
        case JSON_OBJECT: stringify_object(buff, elem); break;
    }
}

str_t *json_stringify(json_elem_t *json)
{
    str_t *buff = str_screate(1024);

    stringify_data(&buff, json);

    return buff;
}
