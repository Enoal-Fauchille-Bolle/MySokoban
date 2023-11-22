/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** task06
*/

int my_is_prime(int nb)
{
    if (nb == 1) {
        return 0;
    }
    if (nb <= 0) {
        return 0;
    }
    for (int i = 2; i <= nb / 2; i++) {
        if (nb % i == 0 && i != 1 && i != nb) {
            return 0;
        }
    }
    return 1;
}
