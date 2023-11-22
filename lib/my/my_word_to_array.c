/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** task03
*/

#include "my.h"

static int get_array_length(char *const *tab)
{
    int i = 0;

    while (tab[i] != 0) {
        i++;
    }
    return i;
}

int my_show_word_array(char *const *tab)
{
    int length = get_array_length(tab);
    int counter = 0;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < my_strlen(tab[i]); j++) {
            my_putchar(tab[i][j]);
            counter++;
        }
        my_putchar('\n');
            counter++;
    }
    return counter;
}
