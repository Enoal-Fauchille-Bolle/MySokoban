/*
** EPITECH PROJECT, 2023
** my_put_in_list
** File description:
** day11
*/

#include <stdlib.h>
#include "my.h"
#include "linked_list.h"

void my_put_in_list(linked_list **list, char *data)
{
    linked_list *element;

    element = malloc(sizeof(*element));
    element -> data = data;
    element -> next = *list;
    *list = element;
}
