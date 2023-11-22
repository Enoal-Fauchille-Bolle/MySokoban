/*
** EPITECH PROJECT, 2023
** my_rev_list
** File description:
** task03
*/

#include <stdlib.h>
#include "my.h"
#include "linked_list.h"

void my_rev_list(linked_list **begin)
{
    linked_list *result = NULL;
    linked_list *tmp;

    tmp = *begin;
    while (tmp != NULL) {
        my_put_in_list(&result, tmp->data);
        tmp = tmp->next;
    }
    *begin = result;
}
