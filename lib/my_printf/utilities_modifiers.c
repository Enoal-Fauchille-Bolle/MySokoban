/*
** EPITECH PROJECT, 2023
** char in modifiers
** File description:
** return 1 if the char is in the modfiers string in the position wanted
*/
#include "my.h"
#include "my_printf.h"

int in_modifiers(int pos, char to_search, char *modifiers)
{
    int counter_slash = 0;

    for (int i = 0; i < my_strlen(modifiers); i++) {
        if (modifiers[i] == '/') {
            counter_slash++;
        }
        if (modifiers[i] == to_search && counter_slash == pos) {
            return 1;
        }
    }
    return 0;
}

int number_in_modifiers(int pos, char *modifiers)
{
    int counter_slash = 0;

    for (int i = 0; i < my_strlen(modifiers); i++) {
        if (modifiers[i] == '/') {
            counter_slash++;
        }
        if ((modifiers[i] >= '0' && modifiers[i] <= '9') &&
            counter_slash == pos) {
            return i;
        }
    }
    return -1;
}

int my_getnbr_modifiers(char *modifiers)
{
    int number = 0;
    int len = 0;

    while (modifiers[len] != '/' && modifiers[len] != '\0') {
        len++;
    }
    for (int i = (len - 1); i >= 0; i--) {
        number += (modifiers[len - i - 1] - '0') * my_compute_power_rec(10, i);
    }
    return number;
}

int absolue(int nb)
{
    if (nb < 0) {
        return -nb;
    }
    return nb;
}

void calcul_nb_character(int nb, int *nb_character_nb)
{
    int len = 1;

    while ((absolue(nb) / my_compute_power_rec(10, len - 1)) >= 10) {
        len++;
    }
    *nb_character_nb = len;
}
