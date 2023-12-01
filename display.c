/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** Display File
*/

#include "my.h"
#include "my_printf.h"
#include "mysokoban.h"
#include "display.h"
#include <curses.h>

static int get_map_width(char **map)
{
    int max = 0;

    for (int i = 0; map[i] != NULL; i++) {
        if (my_strlen(map[i]) > max)
            max = my_strlen(map[i]);
    }
    return max;
}

static int get_map_height(char **map)
{
    int i = 0;

    for (; map[i] != NULL; i++) {
    }
    return i;
}

void display(WINDOW *window, game_t *game)
{
    int screen_width = 0;
    int screen_height = 0;
    int width = get_map_width(game->map);
    int height = get_map_height(game->map);

    getmaxyx(window, screen_height, screen_width);
    if (screen_width < width || screen_height < height) {
        mvprintw((screen_height - 1) / 2,
            (screen_width / 2) - (29 / 2), "Please enlarge your terminal");
        return;
    }
    for (int i = 0; i < height; i++) {
        mvprintw((screen_height - 1) / 2 - height / 2 + i,
            (screen_width / 2) - (width / 2),
            game->map[i]);
    }
}
