/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** Main File
*/

#include "my.h"
#include "my_printf.h"
#include "mysokoban.h"
#include <unistd.h>

static int help_page(void)
{
    my_printf("USAGE\n");
    my_printf("    ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("    map file representing the warehouse map, ");
    my_printf("containing '#' for walls,\n");
    my_printf("    'P' for the player, 'X' for boxes and 'O' ");
    my_printf("for storage locations.\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc >= 2 && my_strcmp(argv[1], "-h") == 0)
        return help_page();
    else if (argc >= 2) {
        return mysokoban(argv[1]);
    } else {
        write(2, "Please specify a map file\n", 27);
        return 84;
    }
}
