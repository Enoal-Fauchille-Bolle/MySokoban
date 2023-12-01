/*
** EPITECH PROJECT, 2023
** my_str_get_nindex
** File description:
** Get the index of the n occurence of a character in a string
*/

#include "my.h"

int my_str_get_nindex(char *str, char c, int occurence)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && occurence == 0)
            return i;
        if (str[i] == c && occurence > 0)
            occurence--;
    }
    return -1;
}
