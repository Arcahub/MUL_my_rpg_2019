/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include "my_game.h"

typedef enum {
    MAIN_MENU_SCENE,
    GALAXIE_SCENE,
    VILLAGE_SCENE
} scene_index;

int check_error(int, char **, char **);
game_t *init_game(void);
void destroy_game(game_t *);

#endif /* !RPG_H_ */
