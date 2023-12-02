/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** Display File
*/

#include "my.h"
#include "my_printf.h"
#include "parsing.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

static int get_height_from_strmap(char **strmap)
{
    char *strmap_tmp = *strmap;
    int height = my_str_char_counter('\n', strmap_tmp);

    if (strmap_tmp[my_strlen(strmap_tmp) - 1] != '\n') {
        height += 1;
        *strmap = my_strconcat(strmap_tmp, "\n");
    }
    return height;
}

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

static void check_map(char **map)
{
    check_map_chars(map);
    check_player(map);
    check_boxes_and_storages(map);
}

char **strmap_to_2d_arr(char *strmap)
{
    int height = get_height_from_strmap(&strmap);
    char **map = malloc(sizeof(char *) * height + 1);

    if (strmap == NULL)
        exit(84);
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) *
            my_str_get_nindex(strmap, '\n', i - 1) -
            my_str_get_nindex(strmap, '\n', i));
        map[i] = my_slice(strmap,
            my_str_get_nindex(strmap, '\n', i - 1) + 1,
            my_str_get_nindex(strmap, '\n', i));
    }
    map[height] = NULL;
    check_map(map);
    return map;
}

position_t **parse_storages(char **map, char *strmap)
{
    int storages_count = my_str_char_counter('O', strmap);
    position_t **storages = malloc(sizeof(position_t *) *
        (storages_count + 1));
    int i = 0;

    for (int row = 0; map[row] != NULL; row++) {
        if (my_str_include(map[row], 'O')) {
            storages[i] = malloc(sizeof(position_t));
            *storages[i] = (position_t)
                { my_str_get_index(map[row], 'O'), row };
            i++;
        }
    }
    storages[storages_count] = NULL;
    return storages;
}
