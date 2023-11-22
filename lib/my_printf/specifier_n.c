/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** specifier_s
*/
#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

void specifier_n(va_list list, int *counter, char *modifiers)
{
    int *p = va_arg(list, int *);

    modifiers = modifiers;
    *p = *counter;
}
