/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** Parsing Header
*/

#ifndef PARSING_H_
    #define PARSING_H_

    #include "mysokoban.h"

position_t **parse_storages(char **map, char *strmap);
char **strmap_to_2d_arr(char *strmap);

#endif /* PARSING_H_ */
