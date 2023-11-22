/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** task07
*/

static int my_find_prime_sup_is_prime(int nb)
{
    if (nb == 1) {
        return 0;
    }
    if (nb <= 0) {
        return 0;
    }
    for (int i = 1; i <= 9; i ++) {
        if (nb % i == 0 && i != 1 && i != nb) {
            return 0;
        }
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    if (my_find_prime_sup_is_prime(nb)) {
        return nb;
    }
    return my_find_prime_sup(nb + 1);
}
