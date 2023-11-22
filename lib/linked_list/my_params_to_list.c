/*
** EPITECH PROJECT, 2023
** my_params_to_list
** File description:
** task01
*/

#include <stdlib.h>
#include "my.h"
#include "linked_list.h"

linked_list *my_params_to_list(int ac, char *const *av)
{
    linked_list *list = NULL;

    for (int i = 0; i < ac; i++) {
        my_put_in_list(&list, av[i]);
    }
    return list;
}
