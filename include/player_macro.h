/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#ifndef MACRO_PLAYER_H_
#define MACRO_PLAYER_H_

static const int PLAYER_DOWN = 0;
static const int PLAYER_UP = 1;
static const int PLAYER_LEFT = 2;
static const int PLAYER_RIGHT = 3;
static const int SPEED = 5;

bool update_player(game_object_t *object, scene_t *scene);
#endif /* !PLAYER_H_ */