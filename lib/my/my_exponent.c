/*
** EPITECH PROJECT, 2023
** my_exponent
** File description:
** my_exponent
*/

int my_exponent(int x, int y)
{
    int result = 1;

    for (int i = 0; i < y; i++) {
        result = result * x;
    }
    return result;
}
