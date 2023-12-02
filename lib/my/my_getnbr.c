/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** task05
*/

#include "my.h"

static int my_getnbr_parse(char const *str, int start, int end, int negative)
{
    int result = 0;
    int n;

    for (int i = start ; i <= end; i++) {
        n = str[i] - 48;
        if (negative) {
            result -= n * my_exponent(10, end - i);
        } else {
            result += n * my_exponent(10, end - i);
        }
    }
    return result;
}

static int my_getnbr_length(int nb, int positive)
{
    int length = 0;

    if (positive) {
        while (nb >= 1) {
            nb = nb / 10;
            length += 1;
        }
    } else {
        while (nb <= -1) {
            nb = nb / 10;
            length += 1;
        }
    }
    return length;
}

static int my_getnbr_get_start(char const *str)
{
    int i = 0;

    while (!(48 <= str[i] && str[i] <= 57)) {
        i++;
    }
    return i;
}

static int my_getnbr_get_end(const char *str, int start)
{
    int result = start;

    while (48 <= str[result] && str[result] <= 57) {
        result++;
    }
    result -= 1;
    return result;
}

static int my_getnbr_move_start(char const *str, int start)
{
    int result = start;

    while (48 == str[result]) {
        result++;
    }
    return result;
}

int my_getnbr(char const *str)
{
    int start = my_getnbr_get_start(str);
    int negative = str[start - 1] == 45;
    int end = my_getnbr_get_end(str, start);
    int result;

    result = my_getnbr_parse(str, start, end, negative);
    start = my_getnbr_move_start(str, start);
    if (end - start + 1 != my_getnbr_length(result, !negative)) {
        return 0;
    }
    return result;
}
