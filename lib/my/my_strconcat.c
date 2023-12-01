/*
** EPITECH PROJECT, 2023
** my_strconcat
** File description:
** Concatenate 2 strings
*/

#include "my.h"
#include <stdlib.h>

char *my_strconcat(char *a, char *b)
{
    char *result = malloc(sizeof(char) * my_strlen(a) + my_strlen(b));
    int i = 0;

    while (a[i] != '\0') {
        result[i] = a[i];
        i++;
    }
    while (b[i - my_strlen(a)] != '\0') {
        result[i] = b[i - my_strlen(a)];
        i++;
    }
    return result;
}
