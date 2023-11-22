/*
** EPITECH PROJECT, 2023
** printing
** File description:
** printing spaces and zeros
*/
#include "my.h"

int print_spaces(int nb_spaces)
{
    for (int i = 0; i < nb_spaces; i++) {
        my_putchar(' ');
    }
    if (nb_spaces > 0) {
        return nb_spaces;
    }
    return 0;
}

int print_zeros(int nb_zeros)
{
    for (int i = 0; i < nb_zeros; i++) {
        my_putchar('0');
    }
    if (nb_zeros > 0) {
        return nb_zeros;
    }
    return 0;
}
