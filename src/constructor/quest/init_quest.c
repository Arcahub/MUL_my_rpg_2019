/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/quest/quest.h"

quest_t *rpg_quest_get_from_conf(char *path, game_t *game, scene_t *scene)
{
    quest_t *quest = malloc(sizeof(quest_t));
    json_object_t *js = json_create_from_file((char *) path);

    if (quest == NULL || js == NULL)
        return (NULL);
    rpg_quest_load_step_from_conf(js, game, scene);
    json_object_destroy(js);
    return (quest);
}