/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** Parsing Header
*/

#ifndef CHECKING_H_
    #define CHECKING_H_

    #include "mysokoban.h"

void check_map(char **map);
void check_win(game_t *game);
void check_lose(game_t *game);

#endif /* CHECKING_H_ */
