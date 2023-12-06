/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** Movement Header
*/

#ifndef MOVEMENT_H_
    #define MOVEMENT_H_

    #include <curses.h>

void move_up(game_t *game);
void move_down(game_t *game);
void move_left(game_t *game);
void move_right(game_t *game);

#endif /* MOVEMENT_H_ */
