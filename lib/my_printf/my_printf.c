/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/

#include "my_printf.h"
#include "my.h"
#include <stdlib.h>
#include <stdarg.h>

void (*SPECIFIER_FUNCTIONS[]) (va_list, int *, char *) = { specifier_s,
    specifier_c, specifier_i_and_d, specifier_i_and_d, specifier_percent,
    specifier_x, specifier_o, specifier_x_maj, specifier_b, specifier_b_maj,
    specifier_p, specifier_n, specifier_f, specifier_f_maj,
    specifier_u, specifier_f_maj, specifier_e, specifier_e_maj };
static void parse_format(va_list list, char *str, int *i, int *counter)
{
    int j = *i + 1;
    int start = *i;
    int end = -1;

    while (str[j] != '\0' && end == -1) {
        if (my_str_include(SPECIFIER_CALLS, str[j]))
            end = j;
        j++;
    }
    if (end != -1) {
        *i += end - start;
        SPECIFIER_FUNCTIONS[my_str_get_index(SPECIFIER_CALLS, str[end])](
            list, counter, separate_modifiers_from_str(my_slice(str,
            start + 1, end - 1)));
    }
}

static void parse_char(va_list list, char *str, int *i,
    int *counter)
{
    if (str[*i] == '%') {
        parse_format(list, str, i, counter);
    } else {
        my_putchar(str[*i]);
        *counter += 1;
    }
}

int my_printf(const char *restrict str, ...)
{
    va_list list;
    int i = 0;
    int counter = 0;

    va_start(list, str);
    while (str[i] != '\0') {
        parse_char(list, (char *)str, &i, &counter);
        i++;
    }
    va_end(list);
    return counter;
}
