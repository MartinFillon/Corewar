/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** free a json object
*/

#include "my_map.h"
#include "my_stdlib.h"
#include "my_vec.h"

#include "./include/json.h"

void json_free(json_elem_t *json)
{
    switch (json->type) {
        case JSON_STRING:
            free(json->value.string);
            break;
        case JSON_ARRAY:
            vec_free_fn(json->value.array, (void (*)(void*))&json_free);
            break;
        case JSON_OBJECT:
            map_free(json->value.object, (void (*)(void*))&json_free);
            break;
        default:
            break;
    }
    free(json);
}
