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

char **strmap_to_2d_arr(char *strmap)
{
    int height;
    char **map;

    if (strmap == NULL)
        exit(84);
    height = get_height_from_strmap(&strmap);
    map = malloc(sizeof(char *) * height + 1);
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) *
            my_str_get_nindex(strmap, '\n', i - 1) -
            my_str_get_nindex(strmap, '\n', i));
        map[i] = my_slice(strmap,
            my_str_get_nindex(strmap, '\n', i - 1) + 1,
            my_str_get_nindex(strmap, '\n', i));
    }
    map[height] = NULL;
    return map;
}

void parse_storages_char(char **map, position_t pos, position_t ***storages,
    int *i)
{
    position_t **tmp = *storages;

    if (map[pos.y][pos.x] == 'O') {
        tmp[*i] = malloc(sizeof(position_t));
        *tmp[*i] = (position_t) { pos.x, pos.y };
        *i += 1;
    }
    *storages = tmp;
}

position_t **parse_storages(char **map, char *strmap)
{
    int storages_count = my_str_char_counter('O', strmap);
    position_t **storages = malloc(sizeof(position_t *) *
        (storages_count + 1));
    int i = 0;

    for (int row = 0; map[row] != NULL; row++) {
        for (int col = 0; map[row][col] != '\0'; col++) {
            parse_storages_char(map, (position_t) { col, row },
                &storages, &i);
        }
    }
    storages[storages_count] = NULL;
    return storages;
}
