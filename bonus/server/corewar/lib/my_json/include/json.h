/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** json parser private declarations
*/

#ifndef LIB_MY_JSON_
    #define LIB_MY_JSON_

    #include <stdarg.h>

    #include "my_map.h"
    #include "my_json.h"


typedef struct json_state_s {
    json_elem_t *self;
    str_t *parent;

    str_t *data;
    size_t data_idx;
} json_state_t;

// Types
int parse_object(json_state_t *state);
int parse_array(json_state_t *state);
int parse_boolean(json_state_t *state);
int parse_number(json_state_t *state);
int parse_string(json_state_t *state);
int parse_value(json_state_t *state);

// Utils
int parse_key(json_state_t *st);
int skip_whitespace(json_state_t *st);
void append_value(json_state_t *st, json_elem_t *value);
int next_char(json_state_t *st);
int get_char(json_state_t *st);
json_elem_t *get_va_value(int ac, va_list *ap, json_elem_t const *json);


#endif /* LIB_MY_JSON_ */
