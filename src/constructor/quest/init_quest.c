/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest.c
*/

#include "my_game.h"
#include "my_json.h"
#include "quest/quest.h"

quest_t *rpg_quest_get_from_conf(json_object_t *js, game_t *game, scene_t *scene)
{
    quest_t *quest = malloc(sizeof(quest_t));

    if (quest == NULL)
        return (NULL);
    return (quest);
}