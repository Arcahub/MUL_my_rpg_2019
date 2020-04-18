/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** quest_handler
*/

#ifndef BOARD_H_
#define BOARD_H_

#include "my_game.h"

typedef struct quest_board {
    sfText *title;
    sfText **steps;
    sfText *actual_step;
    int number_of_step;
    int step_to_draw;
} quest_board_t;

#endif /* !BOARD_H_ */
