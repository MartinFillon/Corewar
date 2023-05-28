/*
** EPITECH PROJECT, 2023
** my_stdlib
** File description:
** my_ftoa
*/

#include "my_utils.h"
#include "my_cstr.h"
#include "./include/my_ftoa.h"

void my_ftoa_init_buffers(char *res, char *power);

static void add_power_to_res(char *res, char *power)
{
    int acc = 0;
    int carry = 0;

    for (int i = 1; i < FLOAT_PART; ++i) {
        acc = (res[RES_SIZE - i] - '0') + (power[FLOAT_PART - i] - '0') + carry;
        res[RES_SIZE - i] = (acc % 10) + '0';
        carry = acc / 10;
    }
}

static void divide_str_by_2(char *str)
{
    int digit = 0;
    int carry = 0;

    while (*str) {
        if (*str != '.') {
            digit = (*str - '0') + (carry * 10);
            *str = (digit / 2) + '0';
            carry = digit % 2;
        }
        str++;
    }
}

static void multiply_str_by_2(char *str)
{
    char *begin = str;
    int carry = 0;
    int digit = 0;

    str += RES_SIZE - 1;
    while (begin <= str) {
        if (*str != '.') {
            digit = (*str - '0') * 2 + carry;
            *str = (digit % 10) + '0';
            carry = digit / 10;
        }
        str--;
    }
}

static char *apply_sign_and_precision(char *res, int sign, int precision)
{
    int first_digit = 0;
    int i = INT_PART + 1 + precision + 1;
    int carry = res[i] >= '5';
    int digit = 0;

    res[i--] = '\0';
    while (res[first_digit + sign] == '0' && res[first_digit + sign + 1] != '.')
        first_digit++;
    while (carry) {
        if (res[i] != '.') {
            digit = (res[i] - '0') + carry;
            res[i] = (digit % 10) + '0';
            carry = digit / 10;
        }
        i--;
    }
    if (sign)
        res[first_digit] = '-';
    return my_strdup(res + first_digit);
}

char *my_ftoa(double nb, int precision)
{
    ieee_double_t bytes = {.init = nb};
    char res[RES_SIZE + 1];
    char power[FLOAT_PART + 1];
    int should_divide = (bytes.ieee.exponent - 1023) < 0;

    my_ftoa_init_buffers(res, power);
    precision = MIN(ABS(precision), FLOAT_PART - 1);
    bytes.ieee.exponent = ABS(bytes.ieee.exponent - 1023);

    for (uint64_t mask = 1UL << 51; mask != 0; mask >>= 1) {
        if (mask != (1UL << 51))
            divide_str_by_2(power);
        if (bytes.ieee.mantissa & mask)
            add_power_to_res(res, power);
    }
    for (int i = 0; i < bytes.ieee.exponent; ++i)
        (should_divide) ? divide_str_by_2(res) : multiply_str_by_2(res);

    return apply_sign_and_precision(res, bytes.ieee.sign, precision);
}
