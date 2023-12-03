/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** MySokoban File
*/

#include "my.h"
#include "my_printf.h"
#include "mysokoban.h"
#include "parsing.h"
#include "display.h"
#include "checking.h"
#include "movement.h"
#include <curses.h>

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
        key_event(current_key, &game, strmap);
        check_win(&game);
        check_lose(&game);
        display(window, &game);
        refresh();
        if (game.game_ended)
            break;
        current_key = getch();
    } while (!game.game_ended && current_key != 27);
    endwin();
    return !game.win;
}
