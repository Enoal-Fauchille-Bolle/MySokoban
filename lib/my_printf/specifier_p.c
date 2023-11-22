/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** specifier_s
*/
#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

void specifier_p(va_list list, int *counter, char *modifiers)
{
    unsigned int p = va_arg(list, unsigned int);

    modifiers = modifiers;
    *counter += my_printf("%#x", p);
}
