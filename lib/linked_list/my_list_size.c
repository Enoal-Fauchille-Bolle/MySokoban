/*
** EPITECH PROJECT, 2023
** my_list_size
** File description:
** task02
*/

#include <stdlib.h>
#include "linked_list.h"

int my_list_size(linked_list const *begin)
{
    int counter = 0;
    linked_list *tmp;

    tmp = (linked_list *)begin;
    while (tmp != NULL) {
        tmp = tmp -> next;
        counter++;
    }
    return counter;
}
