/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** task05
*/

#include <stdlib.h>

static char *get_result(char const *str, int start)
{
    char *result = malloc(sizeof(char *));
    int i = start;
    int j = 0;

    while (str[i] != '\0') {
        result[j] = str[i];
        i++;
        j++;
    }
    return result;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int finded = 0;
    int find_start = 0;

    while (str[i] != '\0' && to_find[finded] != '\0') {
        if (str[i] == to_find[finded] && finded == 0) {
            find_start = i;
        }
        if (str[i] == to_find[finded]) {
            finded++;
        }
        i++;
    }
    return get_result(str, find_start);
}
