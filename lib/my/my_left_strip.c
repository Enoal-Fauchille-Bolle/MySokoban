/*
** EPITECH PROJECT, 2023
** my_left_strip
** File description:
** Removes chars at the start of a string
*/

#include "my.h"
#include <stdio.h>

char *my_left_strip(char *str, char c)
{
    int start = 0;
    int i = start;

    while (str[i] != '\0' && str[i] == c) {
        i++;
    }
    start = i;
    return my_slice(str, start, my_strlen(str) - 1);
}
