/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** Display File
*/

#include "my.h"
#include "my_printf.h"
#include "map_parsing.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

static void check_map_char(char c)
{
    if (c != '#' && c != ' ' && c != 'P' && c != 'O' && c != 'X') {
        write(2, "Invalid map\n", 13);
        exit(84);
    }
}

static void check_map_chars(char **map)
{
    for (int row = 0; map[row] != NULL; row++) {
        for (int col = 0; map[row][col] != '\0'; col++) {
            check_map_char(map[row][col]);
        }
    }
}

static void check_player_loop(char c, int *player_count)
{
    if (c == 'P')
        *player_count += 1;
}

static void check_player(char **map)
{
    int player_count = 0;

    for (int row = 0; map[row] != NULL; row++) {
        for (int col = 0; map[row][col] != '\0'; col++) {
            check_player_loop(map[row][col], &player_count);
        }
    }
    if (player_count != 1) {
        write(2, "Invalid map\n", 13);
        exit(84);
    }
}

static void check_boxes_and_storages_loop(char c, int *boxes_count,
    int *storages_count)
{
    if (c == 'X')
        *boxes_count += 1;
    if (c == 'O')
        *storages_count += 1;
}

static void check_boxes_and_storages(char **map)
{
    int boxes_count = 0;
    int storages_count = 0;

    for (int row = 0; map[row] != NULL; row++) {
        for (int col = 0; map[row][col] != '\0'; col++) {
            check_boxes_and_storages_loop(map[row][col], &boxes_count,
                &storages_count);
        }
    }
    if (boxes_count != storages_count) {
        write(2, "Invalid map\n", 13);
        exit(84);
    }
}

void check_map(char **map)
{
    check_map_chars(map);
    check_player(map);
    check_boxes_and_storages(map);
}
