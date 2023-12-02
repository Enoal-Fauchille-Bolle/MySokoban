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
    int game_ended;
    int win;
} game_t;

int mysokoban(char *filepath);
game_t init_game(char *strmap);
void key_event(int key, game_t *game, char *strmap);

#endif /* MYSOKOBAN_H_ */
