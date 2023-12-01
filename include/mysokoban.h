/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** MySokoban Header
*/

#ifndef MYSOKOBAN_H_
    #define MYSOKOBAN_H_

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct game_s {
    char **map;
    position_t **storages;
} game_t;

int mysokoban(char *filepath);

#endif /* MYSOKOBAN_H_ */
