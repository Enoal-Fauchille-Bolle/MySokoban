/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** specifier_i_and_d
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

void specifier_i_and_d(va_list list, int *counter, char *modifiers)
{
    *counter += my_put_nbr2(list, modifiers);
}
