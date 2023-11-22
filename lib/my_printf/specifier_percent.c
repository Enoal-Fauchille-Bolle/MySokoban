/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** specifier_percent
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

void specifier_percent(va_list list, int *counter, char *modifiers)
{
    (void)list;
    (void)modifiers;
    my_putstr("%");
    *counter += 1;
}
