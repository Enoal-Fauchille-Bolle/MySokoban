/*
** EPITECH PROJECT, 2023
** check_malloc
** File description:
** Check if malloc() failed
*/

#include <stdlib.h>
#include <unistd.h>

void check_malloc(void *value)
{
    if (value == NULL) {
        write(2, "Error while using malloc()\n", 28);
        exit(84);
    }
}
