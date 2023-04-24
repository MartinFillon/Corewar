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

static void print_data(int fd, int level, json_elem_t *elem);

static void print_object(int fd, int level, json_elem_t *elem)
{
    vec_str_t *keys = map_get_keys(elem->value.object);
    str_t *indent = str_screate(level * 4);

    for (int i = 0; i < level; i++)
        str_add(&indent, "    ");

    my_dprintf(fd, "{\n");
    for (size_t i = 0; i < keys->size; i++) {
        my_dprintf(fd, "%S\"%S\": ", indent, keys->data[i]);
        print_data(fd, level + 1, map_get(elem->value.object, keys->data[i]));
        my_dprintf(fd, "%s\n", (i != keys->size - 1) ? "," : "");
    }
    str_slice(&indent, 0, indent->length - 4);
    my_dprintf(fd, "%S}", indent);
    vec_free(keys);
    free(indent);
}

static void print_array(int fd, int level, json_elem_t *elem)
{
    vec_json_t *array = elem->value.array;

    my_dprintf(fd, "[ ");
    for (size_t i = 0; i < array->size; i++) {
        print_data(fd, level + 1, array->data[i]);
        if (i != array->size - 1)
            my_dprintf(fd, ", ");
    }
    my_dprintf(fd, " ]");
}

static void print_data(int fd, int level, json_elem_t *elem)
{
    switch (elem->type) {
        case JSON_STRING: my_dprintf(fd, "\"%S\"", elem->value.string); break;
        case JSON_LONG: my_dprintf(fd, "%ld", (long)elem->value.number); break;
        case JSON_DOUBLE: my_dprintf(fd, "%.2f", elem->value.number); break;
        case JSON_BOOLEAN:
            my_dprintf(fd, "%s", elem->value.boolean ? "true" : "false");
            break;
        case JSON_ARRAY: print_array(fd, level, elem); break;
        case JSON_OBJECT: print_object(fd, level, elem); break;
    }
}

int json_print(json_elem_t *json)
{
    print_data(1, 1, json);
    my_dprintf(1, "\n");
    return 0;
}

int json_write_file(json_elem_t *json, char const *file_path)
{
    int fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0 || json == NULL)
        return -1;

    print_data(fd, 1, json);
    my_dprintf(fd, "\n");

    return 0;
}
