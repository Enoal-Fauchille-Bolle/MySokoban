/*
** EPITECH PROJECT, 2023
** my_sort_str_array
** File description:
** Sort a string array alphabetically
*/

#include "my.h"

static int my_strcmp2(char const *s1, char const *s2)
{
    int i = 0;
    char *temp1 = my_strlowcase((char *)s1);
    char *temp2 = my_strlowcase((char *)s2);

    while (temp1[i] == temp2[i]) {
        i++;
        if (temp1[i] == '\0' && temp2[i] == '\0') {
            return 0;
        }
    }
    return temp1[i] > temp2[i];
}

static void my_sort_str_array_loop(char **array, int size)
{
    char *temp;

    for (int i = 0; i < size - 1; i++) {
        if (my_strcmp2(array[i], array[i + 1])) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }
}

static int is_str_array_sorted(char **array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (my_strcmp2(array[i], array[i + 1])) {
            return 0;
        }
    }
    return 1;
}

void my_sort_str_array(char **array, int size)
{
    while (!is_str_array_sorted(array, size)) {
        my_sort_str_array_loop(array, size);
    }
}
