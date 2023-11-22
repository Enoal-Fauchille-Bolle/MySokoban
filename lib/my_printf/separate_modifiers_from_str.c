/*
** EPITECH PROJECT, 2023
** separate modifiers from str
** File description:
** separate modifiers with a '/'
*/
#include "my_printf.h"
#include "my.h"
#include <stdlib.h>

static int check_in_modifiers(char c, char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (c == str[i]) {
            return 1;
        }
    }
    return 0;
}

static int status_modifiers_zero(char *str, char *str_cpy, int *j, int *i)
{
    if (check_in_modifiers(str[*i], MODIFIERS) == 1) {
        str_cpy[*j] = str[*i];
        *j += 1;
        if (*i == my_strlen(str)-1) {
            str_cpy[*j] = '/';
            str_cpy[*j + 1] = '/';
            str_cpy[*j + 2] = '/';
        }
        return 0;
    } else {
        str_cpy[*j] = '/';
        *j += 1;
        return 1;
    }
    return 1;
}

static void if_i_egal_len(char *str, char *str_cpy, int *j, int *i)
{
    if (*i == my_strlen(str)-1) {
        str_cpy[*j] = '/';
        str_cpy[*j + 1] = '/';
    }
}

static int status_modifiers_one(char *str, char *str_cpy, int *j, int *i)
{
    if (str[*i] == '*') {
        str_cpy[*j] = str[*i];
        *j += 1;
        str_cpy[*j] = '/';
        *j += 1;
        *i += 1;
        return 1;
    } else if (str[*i] >= '0' && str[*i] <= '9') {
        str_cpy[*j] = str[*i];
        *j += 1;
        if_i_egal_len(str, str_cpy, j, i);
        return 0;
    } else {
        str_cpy[*j] = '/';
        *j += 1;
        return 1;
    }
}

static void status_two_get_number(char *str, char *str_cpy, int *j, int *i)
{
    *i += 1;
    while (str[*i] >= '0' && str[*i] <= '9') {
        str_cpy[*j] = str[*i];
        *i += 1;
        *j += 1;
    }
    str_cpy[*j] = '/';
    *j += 1;
}

static int status_modifiers_two(char *str, char *str_cpy, int *j, int *i)
{
    if (str[*i] == '.') {
        if (str[*i + 1] == '*') {
            *i += 1;
            str_cpy[*j] = '*';
            *j += 1;
            *i += 1;
            return 1;
        } else {
            status_two_get_number(str, str_cpy, j, i);
            return 1;
        }
    } else {
        str_cpy[*j] = '/';
        *j += 1;
        return 1;
    }
    return 0;
}

static int status_modifiers_three(char *str, char *str_cpy, int *j, int *i)
{
    if (check_in_modifiers(str[*i], LENGTH_MODIFIERS) == 1) {
        str_cpy[*j] = str[*i];
        *j += 1;
        return 0;
    } else {
        if (str_cpy[*j - 1] != '/') {
            str_cpy[*j] = '/';
            *j += 1;
        }
        return 1;
    }
}

static char *lauch_separations(char *str_cpy, char *str)
{
    int status_modifiers = 0;
    int j = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (status_modifiers == 0) {
            status_modifiers += status_modifiers_zero(str, str_cpy, &j, &i);
        }
        if (status_modifiers == 1) {
            status_modifiers += status_modifiers_one(str, str_cpy, &j, &i);
        }
        if (status_modifiers == 2) {
            status_modifiers += status_modifiers_two(str, str_cpy, &j, &i);
        }
        if (status_modifiers == 3) {
            status_modifiers += status_modifiers_three(str, str_cpy, &j, &i);
        }
    }
    return str_cpy;
}

char *separate_modifiers_from_str(char *str)
{
    char *str_cpy = malloc(sizeof(char) * (my_strlen(str) + 3));

    if (str[0] == '\0') {
        my_strcpy(str_cpy, "///");
        return str_cpy;
    }
    return lauch_separations(str_cpy, str);
}
