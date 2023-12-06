/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** Unit Tests
*/

#include "my.h"
#include "mysokoban.h"
#include "game_movements.h"
#include "map_parsing.h"
#include "game_display.h"
#include "map_checking.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <curses.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//////////////////////////////// Map Parsing /////////////////////////////////

Test(mysokoban, check_positions, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n# XO#\n#   #\n#####\n";
    game_t game = init_game(strmap);

    cr_assert_eq(game.map[1][2], 'P');
    cr_assert_eq(game.map[2][2], 'X');
    cr_assert_eq(game.map[2][3], 'O');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, check_storages, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n# XO#\n#O X#\n#####\n";
    game_t game = init_game(strmap);

    cr_assert_eq(game.storages[0]->x, 3);
    cr_assert_eq(game.storages[0]->y, 2);
    cr_assert_eq(game.storages[1]->x, 1);
    cr_assert_eq(game.storages[1]->y, 3);
    free(game.map);
    free(game.storages);
}

Test(mysokoban, strmap_to_2d_arr_null, .init = redirect_all_std, .exit_code = 84) {
    char *strmap = NULL;
    strmap_to_2d_arr(strmap);
}

Test(mysokoban, invalid_file, .init = redirect_all_std, .exit_code = 84) {
    char *strmap = my_read_file("tests/invalid_file.txt");
    strmap_to_2d_arr(strmap);
}

Test(mysokoban, no_backslash_end, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n# XO#\n#O X#\n#####";
    game_t game = init_game(strmap);

    cr_assert_eq(game.map[5], NULL);
    free(game.map);
    free(game.storages);
}

//////////////////////////////// Map Checking ////////////////////////////////

Test(mysokoban, check_map_no_player, .init = redirect_all_std, .exit_code = 84) {
    char *strmap = "####\n#  #\n####\n";
    init_game(strmap);
}

Test(mysokoban, check_map_box_missing, .init = redirect_all_std, .exit_code = 84) {
    char *strmap = "####\n#P #\n#O #\n####\n";
    init_game(strmap);
}

Test(mysokoban, check_map_storage_missing, .init = redirect_all_std, .exit_code = 84) {
    char *strmap = "####\n#P #\n#X #\n####\n";
    init_game(strmap);
}

Test(mysokoban, check_map_invalid_char, .init = redirect_all_std, .exit_code = 84) {
    char *strmap = "####\n#P #\n#d #\n####\n";
    init_game(strmap);
}

//////////////////////////////// Map Movements ///////////////////////////////

// Move

Test(mysokoban, move_up, .init = redirect_all_std) {
    char *strmap = "#####\n#   #\n# P #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    move_up(&game);
    cr_assert_eq(game.map[2][2], ' ');
    cr_assert_eq(game.map[1][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_down, .init = redirect_all_std) {
    char *strmap = "#####\n#   #\n# P #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    move_down(&game);
    cr_assert_eq(game.map[2][2], ' ');
    cr_assert_eq(game.map[3][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_left, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    move_left(&game);
    cr_assert_eq(game.map[1][2], ' ');
    cr_assert_eq(game.map[1][1], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_right, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    move_right(&game);
    cr_assert_eq(game.map[1][2], ' ');
    cr_assert_eq(game.map[1][3], 'P');
    free(game.map);
    free(game.storages);
}

// Move into wall

Test(mysokoban, move_up_into_wall, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    move_up(&game);
    move_up(&game);
    cr_assert_eq(game.map[1][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_down_into_wall, .init = redirect_all_std) {
    char *strmap = "#####\n#   #\n#   #\n# P #\n#####\n";
    game_t game = init_game(strmap);

    move_down(&game);
    move_down(&game);
    cr_assert_eq(game.map[3][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_left_into_wall, .init = redirect_all_std) {
    char *strmap = "#####\n#P  #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    move_left(&game);
    move_left(&game);
    cr_assert_eq(game.map[1][1], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_right_into_wall, .init = redirect_all_std) {
    char *strmap = "#####\n#  P#\n#   #\n#####\n";
    game_t game = init_game(strmap);

    move_right(&game);
    move_right(&game);
    cr_assert_eq(game.map[1][3], 'P');
    free(game.map);
    free(game.storages);
}

// Move box

Test(mysokoban, move_up_into_box, .init = redirect_all_std) {
    char *strmap = "#####\n#   #\n# XO#\n# P #\n#####\n";
    game_t game = init_game(strmap);

    move_up(&game);
    cr_assert_eq(game.map[1][2], 'X');
    cr_assert_eq(game.map[2][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_down_into_box, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n# XO#\n#   #\n#####\n";
    game_t game = init_game(strmap);

    move_down(&game);
    cr_assert_eq(game.map[2][2], 'P');
    cr_assert_eq(game.map[3][2], 'X');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_left_into_box, .init = redirect_all_std) {
    char *strmap = "#####\n# XP#\n# O #\n#####\n";
    game_t game = init_game(strmap);

    move_left(&game);
    cr_assert_eq(game.map[1][1], 'X');
    cr_assert_eq(game.map[1][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_right_into_box, .init = redirect_all_std) {
    char *strmap = "#####\n#PX #\n# O #\n#####\n";
    game_t game = init_game(strmap);

    move_right(&game);
    cr_assert_eq(game.map[1][2], 'P');
    cr_assert_eq(game.map[1][3], 'X');
    free(game.map);
    free(game.storages);
}

// Move box into wall

Test(mysokoban, move_up_into_box_into_wall, .init = redirect_all_std) {
    char *strmap = "#####\n# XO#\n# P #\n#####\n";
    game_t game = init_game(strmap);

    move_up(&game);
    cr_assert_eq(game.map[1][2], 'X');
    cr_assert_eq(game.map[2][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_down_into_box_into_wall, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n# XO#\n#####\n";
    game_t game = init_game(strmap);

    move_down(&game);
    cr_assert_eq(game.map[2][2], 'X');
    cr_assert_eq(game.map[1][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_left_into_box_into_wall, .init = redirect_all_std) {
    char *strmap = "#####\n#XP #\n# O #\n#####\n";
    game_t game = init_game(strmap);

    move_left(&game);
    cr_assert_eq(game.map[1][1], 'X');
    cr_assert_eq(game.map[1][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, move_right_into_box_into_wall, .init = redirect_all_std) {
    char *strmap = "#####\n# PX#\n# O #\n#####\n";
    game_t game = init_game(strmap);

    move_right(&game);
    cr_assert_eq(game.map[1][3], 'X');
    cr_assert_eq(game.map[1][2], 'P');
    free(game.map);
    free(game.storages);
}

// Restore storage location

Test(mysokoban, move_restore_storage_location, .init = redirect_all_std) {
    char *strmap = "#####\n# PX#\n# O #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    move_down(&game);
    cr_assert_eq(game.map[2][2], 'P');
    move_down(&game);
    cr_assert_eq(game.map[2][2], 'O');
    free(game.map);
    free(game.storages);
}

// No wall

Test(my_sokoban, move_up_no_wall, .init = redirect_all_std) {
    char *strmap = "# #\n P \n# #\n";
    game_t game = init_game(strmap);

    move_up(&game);
    cr_assert_eq(game.map[0][1], ' ');
    cr_assert_eq(game.map[1][1], 'P');
    free(game.map);
    free(game.storages);
}

Test(my_sokoban, move_down_no_wall, .init = redirect_all_std) {
    char *strmap = "# #\n P \n# #\n";
    game_t game = init_game(strmap);

    move_down(&game);
    cr_assert_eq(game.map[2][1], ' ');
    cr_assert_eq(game.map[1][1], 'P');
    free(game.map);
    free(game.storages);
}

Test(my_sokoban, move_left_no_wall, .init = redirect_all_std) {
    char *strmap = "# #\n P \n# #\n";
    game_t game = init_game(strmap);

    move_left(&game);
    cr_assert_eq(game.map[1][0], ' ');
    cr_assert_eq(game.map[1][1], 'P');
    free(game.map);
    free(game.storages);
}

Test(my_sokoban, move_right_no_wall, .init = redirect_all_std) {
    char *strmap = "# #\n P \n# #\n";
    game_t game = init_game(strmap);

    move_right(&game);
    cr_assert_eq(game.map[1][2], ' ');
    cr_assert_eq(game.map[1][1], 'P');
    free(game.map);
    free(game.storages);
}

////////////////////////////// Map Gameover ///////////////////////////////////

Test(mysokoban, check_win, .init = redirect_all_std) {
    char *strmap = "#####\n# O #\n# X #\n# P #\n#####\n";
    game_t game = init_game(strmap);

    move_up(&game);
    check_win(&game);
    cr_assert_eq(game.game_ended, 1);
    cr_assert_eq(game.win, 1);
    free(game.map);
    free(game.storages);
}

Test(mysokoban, check_not_lose, .init = redirect_all_std) {
    char *strmap = "#####\n# O #\n#X  #\n#P  #\n#####\n";
    game_t game = init_game(strmap);

    move_up(&game);
    check_lose(&game);
    cr_assert_eq(game.game_ended, 0);
    free(game.map);
    free(game.storages);
}

Test(mysokoban, check_lose, .init = redirect_all_std) {
    char *strmap = "#######\n# O O #\n# XPX #\n#######\n";
    game_t game = init_game(strmap);

    move_left(&game);
    cr_assert_eq(game.game_ended, 0);
    move_right(&game);
    move_right(&game);
    check_lose(&game);
    cr_assert_eq(game.game_ended, 1);
    cr_assert_eq(game.win, 0);
    free(game.map);
    free(game.storages);
}

////////////////////////////// Map Display ///////////////////////////////////

// Test(mysokoban, display, .init = redirect_all_std) {
//     char *strmap = "#####\n# O #\n# X #\n# P #\n#####\n";
//     game_t game = init_game(strmap);
//     WINDOW *window;

//     window = initscr();
//     display(window, &game);
//     cr_assert_stdout_eq_str("#####\n# O #\n# X #\n# P #\n#####\n", "Got\n%s\nExpected\n%s", stdout, "#####\n# O #\n# X #\n# P #\n#####\n");
//     endwin();
//     free(game.map);
//     free(game.storages);
// }

//////////////////////////////////// Keys ///////////////////////////////////

Test(mysokoban, key_up, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n#   #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    key_event(KEY_UP, &game, strmap);
    cr_assert_eq(game.map[2][2], ' ');
    cr_assert_eq(game.map[1][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, key_down, .init = redirect_all_std) {
    char *strmap = "#####\n#   #\n#   #\n# P #\n#####\n";
    game_t game = init_game(strmap);

    key_event(KEY_DOWN, &game, strmap);
    cr_assert_eq(game.map[2][2], ' ');
    cr_assert_eq(game.map[3][2], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, key_left, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    key_event(KEY_LEFT, &game, strmap);
    cr_assert_eq(game.map[1][2], ' ');
    cr_assert_eq(game.map[1][1], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, key_right, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    key_event(KEY_RIGHT, &game, strmap);
    cr_assert_eq(game.map[1][2], ' ');
    cr_assert_eq(game.map[1][3], 'P');
    free(game.map);
    free(game.storages);
}

Test(mysokoban, key_space, .init = redirect_all_std) {
    char *strmap = "#####\n# P #\n#   #\n#####\n";
    game_t game = init_game(strmap);

    key_event(KEY_RIGHT, &game, strmap);
    cr_assert_eq(game.map[1][2], ' ');
    cr_assert_eq(game.map[1][3], 'P');
    key_event(32, &game, strmap);
    cr_assert_eq(game.map[1][2], 'P');
    cr_assert_eq(game.map[1][3], ' ');
    free(game.map);
    free(game.storages);
}
