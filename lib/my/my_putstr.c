/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** task02
*/

#include "my.h"

int my_putstr(char const *str)
{
    int stop = 0;
    int i = 0;
    int length = 0;

    while (stop == 0) {
        my_putchar(str[i]);
        length ++;
        i++;
        if (str[i] == '\0') {
            stop = 1;
        }
    }
    return length;
}
