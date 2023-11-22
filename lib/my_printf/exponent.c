/*
** EPITECH PROJECT, 2023
** exponent
** File description:
** exponent
*/

int exponent(int x, int y)
{
    int result = 1;

    for (int i = 0; i < y; i++) {
        result = result * x;
    }
    return result;
}
