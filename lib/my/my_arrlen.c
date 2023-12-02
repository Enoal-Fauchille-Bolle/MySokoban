/*
** EPITECH PROJECT, 2023
** my_arrlen
** File description:
** Counts and return the number of elements of an array ended by NULL
*/

#include <stddef.h>

int my_arrlen(void **arr)
{
    int i = 0;

    while (arr[i] != NULL) {
        i++;
    }
    return i;
}
