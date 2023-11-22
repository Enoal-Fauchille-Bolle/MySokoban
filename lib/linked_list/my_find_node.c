/*
** EPITECH PROJECT, 2023
** my_find_node
** File description:
** task06
*/

#include <stdlib.h>
#include "my.h"
#include "linked_list.h"

linked_list *my_find_node(linked_list const *begin,
    void const *data_ref, int (*cmp)())
{
    linked_list *tmp;
    linked_list *result = NULL;

    tmp = (linked_list *)begin;
    while (tmp != NULL) {
        if ((*cmp)(tmp -> data, data_ref) == 0) {
            result = tmp;
            break;
        }
        tmp = tmp -> next;
    }
    return result;
}
