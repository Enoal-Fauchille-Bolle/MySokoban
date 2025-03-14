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

void check_win(game_t *game)
{
    int boxes_on_storages = 0;

    for (int i = 0; game->storages[i] != NULL; i++) {
        if (game->map[game->storages[i]->y][game->storages[i]->x] == 'X')
            boxes_on_storages += 1;
    }
    if (boxes_on_storages == my_arrlen((void **)game->storages)) {
        game->game_ended = 1;
        game->win = 1;
    }
}

static void check_lose_box(game_t *game, int *stuck_boxes, int x, int y)
{
    if (game->map[y][x] == 'X') {
        if ((((game->map[y][x + 1] == '#' || game->map[y][x + 1] == 'X') &&
            (game->map[y + 1][x] == '#' || game->map[y + 1][x] == 'X')) ||
            ((game->map[y][x - 1] == '#' || game->map[y][x - 1] == 'X') &&
            (game->map[y + 1][x] == '#' || game->map[y + 1][x] == 'X')) ||
            ((game->map[y][x + 1] == '#' || game->map[y][x + 1] == 'X') &&
            (game->map[y - 1][x] == '#' || game->map[y - 1][x] == 'X')) ||
            ((game->map[y][x - 1] == '#' || game->map[y][x - 1] == 'X') &&
            (game->map[y - 1][x] == '#' || game->map[y - 1][x] == 'X')))) {
                *stuck_boxes += 1;
        }
    }
}

void check_lose(game_t *game)
{
    int stuck_boxes = 0;

    if (game->game_ended)
        return;
    for (int y = 0; game->map[y] != NULL; y++) {
        for (int x = 0; game->map[y][x] != '\0'; x++) {
            check_lose_box(game, &stuck_boxes, x, y);
        }
    }
    if (stuck_boxes == my_arrlen((void **)game->storages)) {
        game->game_ended = 1;
        game->win = 0;
    }
}
