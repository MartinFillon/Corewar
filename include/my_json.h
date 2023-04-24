/*
** EPITECH PROJECT, 2022
** my_json
** File description:
** json parser
*/

#ifndef MY_JSON_
    #define MY_JSON_

    #include "my_map.h"
    #include "my_vec.h"

    #define JSON_OBJ_SIZE   30


enum json_type {
    JSON_LONG,
    JSON_DOUBLE,
    JSON_BOOLEAN,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
};

typedef struct vec_json_s vec_json_t;

typedef struct json_elem_s {
    union {
        double number;
        int boolean;
        str_t *string;
        vec_json_t *array;
        map_t *object;
    } value;
    enum json_type type;
} json_elem_t;

VEC_DEF(json_elem_t *, json)

/**
 * @brief Free the json object
 *
 * @param json json object
 */
void json_free(json_elem_t *json);

/**
 * @brief json stringify
 *
 * @param json  json object
 * @return  stringified object
 */
str_t *json_stringify(json_elem_t *json);

/**
 * @brief Parse the json string
 *
 * @param content  json string
 * @return json object
 */
json_elem_t *json_parse(str_t *content);

/**
 * @brief Create a json object from a file
 *
 * @param file_path path to the file
 * @return json object
 */
json_elem_t *json_from_file(char const *file_path);

/**
 * @brief Write the json object to a file
 *
 * @param json  json object
 * @param file_path  path to the file
 * @return success
 */
int json_write_file(json_elem_t *json, char const *file_path);

/**
 * @brief Print the json object
 *
 * @param json  json object
 * @return success
 */
int json_print(json_elem_t *json);

/**
 * @brief Get the json number from the json object
 *
 * @param json  json object
 * @param ac    number of arguments
 * @param ...   arguments
 * @return the number
 */
double json_get_number(json_elem_t const *json, int ac, ...);

/**
 * @brief Get the json element from the json object
 *
 * @param json  json object
 * @param ac    number of arguments
 * @param ...   arguments
 * @return the element
 */
json_elem_t *json_get(json_elem_t const *json, int ac, ...);

/**
 * @brief Get the json string from the json object
 *
 * @param json  json object
 * @param ac    number of arguments
 * @param ...   arguments
 * @return the string
 */
str_t *json_get_string(json_elem_t const *json, int ac, ...);

/**
 * @brief Get the json array from the json object
 *
 * @param json json object
 * @param ac   number of arguments
 * @param ...  arguments
 * @return the array
 */
vec_json_t *json_get_array(json_elem_t const *json, int ac, ...);

/**
 * @brief Get the json object from the json object
 *
 * @param json json object
 * @param ac   number of arguments
 * @param ...  arguments
 * @return the object
 */
map_t *json_get_object(json_elem_t const *json, int ac, ...);

/**
 * @brief Get the json boolean from the json object
 *
 * @param json json object
 * @param ac   number of arguments
 * @param ...  arguments
 * @return the boolean
 */
int json_get_bool(json_elem_t const *json, int ac, ...);


#endif /* INCLUDE_MY_JSON_ */
