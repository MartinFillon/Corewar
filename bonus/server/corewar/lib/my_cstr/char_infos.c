/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** char info
*/

int my_isupper(char chr)
{
    return (
        chr >= 'A' && chr <= 'Z'
    );
}

int my_islower(char chr)
{
    return (
        chr >= 'a' && chr <= 'z'
    );
}

int my_isnum(char chr)
{
    return (
        chr >= '0' && chr <= '9'
    );
}

int my_isalpha(char chr)
{
    return (
        (chr >= 'A' && chr <= 'Z') ||
        (chr >= 'a' && chr <= 'z')
    );
}

int my_isalphanum(char chr)
{
    return (
        (chr >= 'A' && chr <= 'Z') ||
        (chr >= 'a' && chr <= 'z') ||
        (chr >= '0' && chr <= '9')
    );
}
