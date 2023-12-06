/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** Movement File
*/

#include "my.h"
#include "my_printf.h"
#include "mysokoban.h"
#include <stdlib.h>
#include <curses.h>

static position_t get_player_position(char **map)
{
    position_t position = { -1, -1 };

    for (int row = 0; map[row] != NULL; row++) {
        if (my_str_include(map[row], 'P')) {
            position.x = my_str_get_index(map[row], 'P');
            position.y = row;
        }
    }
    return position;
}

static void reset_position(game_t *game, position_t *position)
{
    int x = position->x;
    int y = position->y;

    for (int i = 0; game->storages[i] != NULL; i++) {
        if (x == game->storages[i]->x && y == game->storages[i]->y) {
            game->map[y][x] = 'O';
            return;
        }
    }
    game->map[y][x] = ' ';
}

void move_up(game_t *game)
{
    position_t player_position = get_player_position(game->map);
    int player_x = player_position.x;
    int player_y = player_position.y;

    if (game->map[player_y - 1][player_x] == '#' || player_y - 2 < 0) {
        return;
    }
    if (game->map[player_y - 1][player_x] != 'X') {
            game->map[player_y - 1][player_x] = 'P';
            game->map[player_y][player_x] = ' ';
    } else {
        if (game->map[player_y - 2][player_x] == '#' ||
            game->map[player_y - 2][player_x] == 'X')
                return;
        game->map[player_y - 2][player_x] = 'X';
        game->map[player_y - 1][player_x] = 'P';
        game->map[player_y][player_x] = ' ';
    }
    reset_position(game, &player_position);
}

void move_down(game_t *game)
{
    position_t player_position = get_player_position(game->map);
    int player_x = player_position.x;
    int player_y = player_position.y;

    if (game->map[player_y + 1][player_x] == '#' ||
        game->map[player_y + 2] == NULL)
            return;
    if (game->map[player_y + 1][player_x] != 'X') {
        game->map[player_y + 1][player_x] = 'P';
        game->map[player_y][player_x] = ' ';
    } else {
        if (game->map[player_y + 2][player_x] == '#' ||
            game->map[player_y + 2][player_x] == 'X')
            return;
        game->map[player_y + 2][player_x] = 'X';
        game->map[player_y + 1][player_x] = 'P';
        game->map[player_y][player_x] = ' ';
    }
    reset_position(game, &player_position);
}

void move_left(game_t *game)
{
    position_t player_position = get_player_position(game->map);
    int player_x = player_position.x;
    int player_y = player_position.y;

    if (game->map[player_y][player_x - 1] == '#' || player_x - 2 < 0)
        return;
    if (game->map[player_y][player_x - 1] != 'X') {
        game->map[player_y][player_x - 1] = 'P';
        game->map[player_y][player_x] = ' ';
    } else {
        if (game->map[player_y][player_x - 2] == '#' ||
            game->map[player_y][player_x - 2] == 'X')
            return;
        game->map[player_y][player_x - 2] = 'X';
        game->map[player_y][player_x - 1] = 'P';
        game->map[player_y][player_x] = ' ';
    }
    reset_position(game, &player_position);
}

void move_right(game_t *game)
{
    position_t player_position = get_player_position(game->map);
    int player_x = player_position.x;
    int player_y = player_position.y;

    if (game->map[player_y][player_x + 1] == '#' ||
        game->map[player_y][player_x + 2] == '\0')
        return;
    if (game->map[player_y][player_x + 1] != 'X') {
        game->map[player_y][player_x + 1] = 'P';
        game->map[player_y][player_x] = ' ';
    } else {
        if (game->map[player_y][player_x + 2] == '#' ||
            game->map[player_y][player_x + 2] == 'X')
            return;
        game->map[player_y][player_x + 2] = 'X';
        game->map[player_y][player_x + 1] = 'P';
        game->map[player_y][player_x] = ' ';
    }
    reset_position(game, &player_position);
}
