/*
** EPITECH PROJECT, 2023
** convert_base.c
** File description:
** Write a function that returns the result from the nbr string conversion
*/
#include "my.h"
#include <stdlib.h>

static int get_value_of_char(char c, char const *base_from)
{
    for (int i = 0; i < my_strlen(base_from); i++) {
        if (c == base_from[i]) {
            return i;
        }
    }
    return -1;
}

static char *convert_base_x(unsigned int nbr,
    char const *base_to, char const *nbr_str)
{
    char *number;
    unsigned int nbr_cpy = nbr;
    int nbr_chars = 0;
    int i = 0;

    while (nbr != 0) {
        nbr = nbr / my_strlen(base_to);
        nbr_chars++;
    }
    if (nbr_str[0] == '-') {
        number = malloc(sizeof(char) * nbr_chars + 1);
        number[nbr_chars] = '-';
    } else
        number = malloc(sizeof(char) * nbr_chars);
    while (nbr_cpy != 0) {
        number[i] = base_to[nbr_cpy % my_strlen(base_to)];
        nbr_cpy = nbr_cpy / my_strlen(base_to);
        i++;
    }
    return number;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int nbr_value = 0;

    if (nbr == 0 || base_from == 0 || base_to == 0)
        return "\0";
    for (int j = 0; j < my_strlen(nbr); j++) {
        nbr_value += get_value_of_char(nbr[j], base_from)
            * my_compute_power_rec(my_strlen(base_from),
            (my_strlen(nbr) - j - 1));
    }
    return my_revstr(convert_base_x(nbr_value, base_to, nbr));
}
