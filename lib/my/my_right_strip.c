/*
** EPITECH PROJECT, 2023
** my_right_strip
** File description:
** Removes chars at the end of a string
*/

#include "my.h"
#include <stdio.h>

char *my_right_strip(char *str, char c)
{
    int end = my_strlen(str) - 1;
    int i = end;

    i = end;
    while (str[i] != '\0' && str[i] == c) {
        i--;
    }
    end = i + 1;
    return my_slice(str, 0, end);
}
