/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** task01
*/


void    my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
