/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** quest_handler
*/

#include "my_game.h"
#include "item/item_id.h"

#ifndef QUEST_HANDLER_H_
#define QUEST_HANDLER_H_

typedef enum {
    INTRODUCTION_QUEST,
    DARK_VADOR
} quest_id;

typedef enum {
    UNTAKEN,
    TAKEN,
    ACHIEVED
} quest_state;

typedef enum {
    DIALOG,
    FIGHT,
    REACH
} step_type;

typedef struct step {
    sfVector2f pos;
    step_type step_type;
    int step_number;
    bool validated;
    char *description;
    char *fight_scene;
    struct step *next;
} step_t;

typedef struct quest {
    quest_state state;
    char *name;
    int number_of_step;
    int reward_money;
    int actual_step;
    item_id reward_item;
    int reward_item_number;
    struct step *step;
    quest_id id;
} quest_t;

step_t *rpg_quest_load_step_from_conf(json_object_t *js, game_t *game, \
scene_t *scene);
void validate_step(game_t *game, scene_t *scene, quest_t *quest);
void validate_quest(game_t *game, scene_t *scene, quest_t *quest);
void rpg_destroy_quest(quest_t *quest);
quest_t *rpg_quest_get_from_conf(char *path, game_t *game, scene_t *scene);

#endif /* !QUEST_HANDLER_H_ */
