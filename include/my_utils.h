/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** stupid utils
*/

#ifndef INCLUDE_MY_UTILS_
    #define INCLUDE_MY_UTILS_

    #define MIN(x, y) ((x) < (y) ? (x) : (y))
    #define MAX(x, y) ((x) > (y) ? (x) : (y))

    #define FABS(x) ((x) < 0.0 ? -(x) : (x))
    #define ABS(x)  ((x) < 0 ? -(x) : (x))

    #define POW2(x) ((x) * (x))

    #define UNUSED __attribute__((unused))

    #define TO_DEG(r)    (r * (180.0 / (float)M_PI))
    #define TO_RAD(r)    (r * ((float)M_PI / 180.0))


#endif /* INCLUDE_MY_UTILS_ */
