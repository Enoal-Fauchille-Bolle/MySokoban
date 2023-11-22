/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** task04
*/

#include <stdlib.h>
#include "my.h"

static int is_alphanumeric(char c)
{
    return ((c >= 'a') && (c <= 'z')) ||
        ((c >= 'A') && (c <= 'Z')) ||
        ((c >= '0') && (c <= '9'));
}

static int count_separator(char const *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] != '\0') {
        if (!is_alphanumeric(str[i])) {
            counter++;
        }
        i++;
    }
    return counter;
}

static char *put_in_array(char const *str, int i, int last_element_start)
{
    if (my_strlen(str) - 1 != i) {
        return my_slice(str, last_element_start, i);
    } else {
        return my_slice(str, last_element_start, i + 1);
    }
}

char **my_str_to_word_array(char const *str)
{
    int separator_count = count_separator(str);
    char **arr = malloc(sizeof(char *) * (separator_count + 1));
    int i = 0;
    int j = 0;
    int last_element_start = 0;

    while (str[i] != '\0') {
        if (!is_alphanumeric(str[i]) || str[i + 1] == '\0') {
            arr[j] = put_in_array(str, i, last_element_start);
            j++;
            last_element_start = i + 1;
        }
        i++;
    }
    return arr;
}
