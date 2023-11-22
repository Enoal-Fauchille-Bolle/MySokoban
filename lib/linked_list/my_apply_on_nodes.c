/*
** EPITECH PROJECT, 2023
** my_apply_on_nodes
** File description:
** task04
*/

#include <stdlib.h>
#include "my.h"
#include "linked_list.h"

int my_apply_on_nodes(linked_list *begin, int (*f)(void *))
{
    linked_list *tmp;

    tmp = begin;
    while (tmp != NULL) {
        (*f)(tmp -> data);
        tmp = tmp -> next;
    }
    return 0;
}
