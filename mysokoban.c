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
#include "movement.h"
#include <curses.h>

void key_event(int key, game_t *game)
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
}

int mysokoban(char *filepath)
{
    char *strmap = my_read_file(filepath);
    char **map = strmap_to_2d_arr(strmap);
    position_t **storages = parse_storages(map, strmap);
    game_t game = { map, storages };
    WINDOW *window;
    int current_key = 0;
    int game_ended = 0;

    window = initscr();
    keypad(window, true);
    (void)storages;
    do {
        key_event(current_key, &game);
        refresh_display(window, &game);
        current_key = getch();
    } while (!game_ended && current_key != 27);
    endwin();
    return 0;
}
