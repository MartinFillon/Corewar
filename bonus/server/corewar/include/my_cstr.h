/*
** EPITECH PROJECT, 2023
** my_cstr
** File description:
** cstring functions
*/

#ifndef INCLUDE_MY_CSTR_
    #define INCLUDE_MY_CSTR_
    #include <stddef.h>


char my_upcase(char chr);
char my_lowcase(char chr);
char *my_strlowcase(char *str);
char *my_strupcase(char *str);

size_t my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, size_t n);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, size_t n);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_revstr(char *str);
int my_streq(char const *s1, char const *s2);
char *my_strchr(char *str, char c);

int my_isalpha(char chr);
int my_islower(char chr);
int my_isnum(char chr);
int my_isupper(char chr);
int my_isalphanum(char chr);

int my_str_isalpha(char const *str);
int my_str_isfloat(char const *str);
int my_str_isint(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);

int my_strstartwith(char const *str, char const *start);
int my_strendwith(char const *str, char const *end);


#endif /* INCLUDE_MY_CSTR_ */
