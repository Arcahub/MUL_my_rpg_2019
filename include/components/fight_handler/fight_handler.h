/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parallax
*/

#include "item/item_id.h"
#include "spaceship/ship.h"
#include "my_game.h"
#include "components/fight_handler/ennemy.h"

#ifndef FIGHT_HANDLER_H_
#define FIGHT_HANDLER_H_

typedef enum {
    ATTACK,
    DODGE,
    REPAIR,
    EMPTY
} action_id;

typedef struct fight_handler {
    bool in_fight;
    bool player_turn;
    int action_number;
    action_id *id;
    game_object_t *button;
    int done;
} fight_handler_t;

item_id rpg_spaceship_get_equiped_weapon(game_object_t *object, \
scene_t *scene);
int rpg_spaceship_get_equip_size(game_object_t *object, scene_t *scene);
int rpg_spaceship_get_damage(game_object_t *object, scene_t *scene);
void rpg_fight_handler_remove_spaceship_life(game_object_t *object, \
scene_t *scene);
void rpg_fight_handler_remove_ennemy_life(game_object_t *object, \
scene_t *scene);
int rpg_fight_handler_get_player_action(game_object_t *object, \
scene_t *scene, int done);
int rpg_fight_handler_make_player_actions(game_object_t *object, \
scene_t *scene);
int rpg_spaceship_get_repair_value(game_object_t *object, scene_t *scene);
int rpg_spaceship_get_dodge_value(game_object_t *object, scene_t *scene);
void rpg_space_ship_destroy(space_ship_t *ship);
int rpg_ennemy_get_damage(game_object_t *object, scene_t *scene);
item_id rpg_ennemy_get_equiped_weapon(game_object_t *object, scene_t *scene);
void rpg_fight_handler_repair_ennemy(game_object_t *object, scene_t *scene);
void rpg_fight_handler_remove_ennemy_life(game_object_t *object, \
scene_t *scene);
void rpg_fight_handler_handle_dodge_spaceship(game_object_t \
*object, int dodge, scene_t *scene);
void rpg_fight_handler_repair_spaceship(game_object_t *object, scene_t *scene);
void rpg_fight_handler_make_ennemy_play(game_object_t *object, scene_t *scene);
void rpg_fight_handler_free_extend(fight_handler_t *handler);
void rpg_fight_handler_draw(sfRenderWindow *window, game_object_t *object);
bool rpg_fight_handler_update(game_object_t *object, scene_t *scene);
int rpg_fight_handler_spaceship_get_repair_statue(scene_t *scene);
int rpg_ennemy_get_dodge_value(game_object_t *object, scene_t *scene);
space_ship_t *rpg_spaceship_get_extend(scene_t *scene);
struct ennemy *rpg_ennemy_get_extend(scene_t *scene);
int rpg_fight_handler_dodge_handle(int number);
fight_handler_t *rpg_fight_handler_get_extend(scene_t *scene);
int rpg_get_left_actions(scene_t *scene);
void rpg_ennemy_destroy(void *ptr);

#endif /* !FIGHT_HANDLER_H_ */