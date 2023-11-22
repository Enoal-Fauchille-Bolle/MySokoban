/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** task01
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    dest = malloc(my_strlen(src));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
