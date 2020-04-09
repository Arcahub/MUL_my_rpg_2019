/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parallax
*/

#include "item/item_id.h"

#ifndef FIGHT_HANDLER_H_
#define FIGHT_HANDLER_H_

typedef enum {
    ATTACK,
    DODGE,
    REPAIR
} action_id;

typedef struct fight_handler {
    bool in_fight;
    bool player_turn;
    int action_number;
    action_id *id;
} fight_handler_t;

item_id rpg_spaceship_get_equiped_weapon(game_object_t *object);
int rpg_spaceship_get_equip_size(game_object_t *object);
int rpg_spaceship_get_damage(game_object_t *object);
void rpg_fight_handler_remove_spaceship_life(game_object_t *object, int damage);
void rpg_fight_handler_remove_ennemy_life(game_object_t *object);
void rpg_fight_handler_get_player_action(game_object_t *object, scene_t *scene);
void rpg_fight_handler_make_player_actions(game_object_t *object, scene_t *scene);
void rpg_fight_handler_handle_dodge(game_object_t *object, int dodge);

#endif /* !FIGHT_HANDLER_H_ */