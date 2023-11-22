/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int result = 0;
    int increment = 1;

    while (nb > 0) {
        nb -= increment;
        result++;
        increment += 2;
    }
    if (nb != 0) {
        return 0;
    }
    return result;
}
