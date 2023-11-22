/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** task07
*/

#include "my.h"

static void my_put_nbr_display(int nb, int length)
{
    int current;

    for (int i = length; i > 0; i--) {
        current = nb / exponent(10, i - 1);
        if (current < 0) {
            current *= -1;
        }
        my_putchar(48 + current);
        nb -= current * exponent(10, i - 1);
    }
}

static int my_put_nbr_length(int nb, int positive)
{
    int length = 0;

    if (positive) {
        while (nb >= 1) {
            nb = nb / 10;
            length += 1;
        }
    } else {
        while (nb <= -1) {
            nb = nb / 10;
            length += 1;
        }
    }
    return length;
}

int my_put_nbr(int nb)
{
    int positive = nb >= 0;
    int length = my_put_nbr_length(nb, positive);

    if (length == 0) {
        my_putchar('0');
    }
    if (!positive) {
        my_putchar('-');
        nb *= -1;
    }
    my_put_nbr_display(nb, length);
    return length;
}
