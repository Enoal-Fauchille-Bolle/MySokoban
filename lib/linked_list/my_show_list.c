/*
** EPITECH PROJECT, 2023
** my_show_list
** File description:
** day11
*/

#include <stdlib.h>
#include "my.h"
#include "linked_list.h"

void my_show_list(linked_list *list)
{
    linked_list *tmp;

    tmp = list;
    while (tmp != NULL) {
        my_putstr(tmp -> data);
        my_putchar('\n');
        tmp = tmp -> next;
    }
}
