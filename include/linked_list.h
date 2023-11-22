/*
** EPITECH PROJECT, 2023
** fileslist
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

    #include <sys/stat.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
    struct linked_list *previous;
} linked_list;

int my_apply_on_matching_nodes(linked_list *begin, int (*f)(void *),
    void const *data_ref, int (*cmp)());
int my_apply_on_nodes(linked_list *begin, int (*f)(void *));
linked_list *my_find_node(linked_list const *begin,
    void const *data_ref, int (*cmp)());
int my_list_size(linked_list const *begin);
linked_list *my_params_to_list(int ac, char *const *av);
void my_put_in_list(linked_list **list, char *data);
void my_rev_list(linked_list **begin);
void my_show_list(linked_list *list);

#endif /* LINKED_LIST_H_ */
