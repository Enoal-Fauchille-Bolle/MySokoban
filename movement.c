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

static position_t *get_player_position(char **map)
{
    for (int row = 0; map[row] != NULL; row++) {
        if (my_str_include(map[row], 'P')) {
            return &(position_t){ my_str_get_index(map[row], 'P'), row };
        }
    }
    return NULL;
}

static void reset_position(game_t *game, position_t *position)
{
    int x = position->x;
    int y = position->y;

    (void)game;
    (void)x;
    (void)y;
}

void move_up(game_t *game)
{
    position_t *player_position = get_player_position(game->map);
    int player_x = player_position->x;
    int player_y = player_position->y;

    if (game->map[player_y - 1][player_x] == '#')
        return;
    if (game->map[player_y - 1][player_x] != 'X') {
        game->map[player_y - 1][player_x] = 'P';
        game->map[player_y][player_x] = ' ';
    } else {
        if (game->map[player_y - 2][player_x] == '#')
            return;
        game->map[player_y - 2][player_x] = 'X';
        game->map[player_y - 1][player_x] = 'P';
        game->map[player_y][player_x] = ' ';
        reset_position(game, player_position);
    }
}

void move_down(game_t *game)
{
    position_t *player_position = get_player_position(game->map);
    int player_x = player_position->x;
    int player_y = player_position->y;

    if (game->map[player_y + 1][player_x] == '#')
        return;
    if (game->map[player_y + 1][player_x] != 'X') {
        game->map[player_y + 1][player_x] = 'P';
        game->map[player_y][player_x] = ' ';
    } else {
        if (game->map[player_y + 2][player_x] == '#')
            return;
        game->map[player_y + 2][player_x] = 'X';
        game->map[player_y + 1][player_x] = 'P';
        game->map[player_y][player_x] = ' ';
    }
}

void move_left(game_t *game)
{
    position_t *player_position = get_player_position(game->map);
    int player_x = player_position->x;
    int player_y = player_position->y;

    if (game->map[player_y][player_x - 1] == '#')
        return;
    if (game->map[player_y][player_x - 1] != 'X') {
        game->map[player_y][player_x - 1] = 'P';
        game->map[player_y][player_x] = ' ';
    } else {
        if (game->map[player_y][player_x - 2] == '#')
            return;
        game->map[player_y][player_x - 2] = 'X';
        game->map[player_y][player_x - 1] = 'P';
        game->map[player_y][player_x] = ' ';
    }
}

void move_right(game_t *game)
{
    position_t *player_position = get_player_position(game->map);
    int player_x = player_position->x;
    int player_y = player_position->y;

    if (game->map[player_y][player_x + 1] == '#')
        return;
    if (game->map[player_y][player_x + 1] != 'X') {
        game->map[player_y][player_x + 1] = 'P';
        game->map[player_y][player_x] = ' ';
    } else {
        if (game->map[player_y][player_x + 2] == '#')
            return;
        game->map[player_y][player_x + 2] = 'X';
        game->map[player_y][player_x + 1] = 'P';
        game->map[player_y][player_x] = ' ';
    }
}
