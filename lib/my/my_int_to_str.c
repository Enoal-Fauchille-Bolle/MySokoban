/*
** EPITECH PROJECT, 2023
** my_int_to_str
** File description:
** Converts int to a string
*/

#include "my.h"
#include <stdlib.h>

static int my_int_to_str_length(int nb)
{
    int length = 0;

    while (nb >= 1) {
        nb = nb / 10;
        length += 1;
    }
    return length;
}

char *my_int_to_str(int nb)
{
    int length = my_int_to_str_length(nb);
    char *result = malloc(sizeof(char) * (length + 1));

    if (nb == 0)
        return "0";
    for (int i = length; i != 0; i--) {
        result[i - 1] = nb % 10 + '0';
        nb /= 10;
    }
    result[length] = '\0';
    return result;
}
