/*
** EPITECH PROJECT, 2023
** my_float
** File description:
** my_float
*/

#ifndef INCLUDE_MY_FLOAT_
    #define INCLUDE_MY_FLOAT_
    #include <stdint.h>

    #define INT_PART    (309)
    #define FLOAT_PART  (1074)
    #define RES_SIZE    (INT_PART + FLOAT_PART + 1)


typedef struct __attribute__((packed)) {
    uint64_t mantissa : 52;
    uint16_t exponent : 11;
    uint16_t sign : 1;
} ieee_bytes_t;

typedef union {
    ieee_bytes_t ieee;
    double init;
} ieee_double_t;


#endif /* INCLUDE_MY_FLOAT_ */
