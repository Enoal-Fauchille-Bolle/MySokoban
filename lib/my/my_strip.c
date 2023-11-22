/*
** EPITECH PROJECT, 2023
** my_strip
** File description:
** Removes chars at the start and the end of a string
*/

#include "my.h"
#include <stdio.h>

char *my_strip(char *str, char c)
{
    int start = 0;
    int end = my_strlen(str) - 1;
    int i = start;

    while (str[i] != '\0' && str[i] == c) {
        i++;
    }
    start = i;
    i = end;
    while (str[i] != '\0' && str[i] == c) {
        i--;
    }
    end = i + 1;
    return my_slice(str, start, end);
}
