/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** specifier_e
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int convert_double(double *number)
{
    int i = 0;
    double temp = *number;

    while ((int)temp != 0) {
        temp /= 10;
        i++;
    }
    *number = temp * 10;
    return i - 1;
}

static void display_round(int round, int after)
{
    if (after >= 5) {
        my_printf("%d", round + 1);
    } else {
        my_printf("%d", round);
    }
}

static void display(double number, int offset, int *counter)
{
    int round;

    my_printf("%d.", (int)number);
    *counter += 2;
    for (int i = 0; i < 7; i++) {
        number = (number - (int)number) * 10;
        if (i <= 4) {
            my_printf("%d", (int)number);
            *counter += 1;
        }
        if (i == 5)
            round = (int)number;
        if (i == 6) {
            display_round(round, (int)number);
            *counter += 1;
        }
    }
    my_printf("e%0+3d", offset);
    *counter += 4;
}

void specifier_e(va_list list, int *counter, char *modifiers)
{
    double number = va_arg(list, double);
    int offset = convert_double(&number);

    display(number, offset, counter);
    (void)modifiers;
}
