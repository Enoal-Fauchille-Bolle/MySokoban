/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** MySokoban File
*/

#include "my.h"
#include "my_printf.h"
#include "mysokoban.h"
#include "map_parsing.h"
#include "game_display.h"
#include "map_checking.h"
#include "game_checking.h"
#include "game_movements.h"
#include <curses.h>
#include <unistd.h>

void key_event(int key, game_t *game, char *strmap)
{
    if (key == KEY_UP) {
        move_up(game);
    }
    if (key == KEY_DOWN) {
        move_down(game);
    }
    if (key == KEY_LEFT) {
        move_left(game);
    }
    if (key == KEY_RIGHT) {
        move_right(game);
    }
    if (key == 32) {
        game->map = strmap_to_2d_arr(strmap);
        game->storages = parse_storages(game->map, strmap);
    }
}

game_t init_game(char *strmap)
{
    char **map = strmap_to_2d_arr(strmap);
    position_t **storages = parse_storages(map, strmap);
    game_t game = { map, storages, 0, 0 };

    check_map(map);
    return game;
}

static void game_refresh(game_t *game, int current_key,
    char *strmap, WINDOW *window)
{
    key_event(current_key, game, strmap);
    check_win(game);
    check_lose(game);
    display(window, game);
}

int mysokoban(char *filepath)
{
    char *strmap = my_read_file(filepath);
    game_t game = init_game(strmap);
    WINDOW *window = initscr();
    int current_key = 0;

    keypad(window, true);
    curs_set(0);
    do {
        clear();
        game_refresh(&game, current_key, strmap, window);
        refresh();
        if (game.game_ended)
            break;
        current_key = getch();
    } while (!game.game_ended && current_key != 27);
    usleep(10000);
    endwin();
    return !game.win;
}
