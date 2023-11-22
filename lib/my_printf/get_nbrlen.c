/*
** EPITECH PROJECT, 2023
** my_nbrlen
** File description:
** Count characters of a integer
*/

#include "my.h"

int get_nbrlen(int nb)
{
    int i = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        i++;
        nb *= -1;
    }
    while (nb > 0) {
        nb /= 10;
        i++;
    }
    return i;
}
