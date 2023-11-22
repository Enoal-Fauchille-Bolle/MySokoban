/*
** EPITECH PROJECT, 2023
** my_str_get_index
** File description:
** Get the index of the 1st occurence of a character in a string
*/

#include "my.h"

int my_str_get_index(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}
