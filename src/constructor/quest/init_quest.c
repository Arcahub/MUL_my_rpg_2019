/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest.c
*/

#include "my_json.h"
#include <stdlib.h>
#include "components/get_from_config.h"
#include "components/quest/quest.h"

void rpg_destroy_quest(quest_t *quest)
{
    if (quest == NULL)
        return;
    free(quest);
}

quest_t *rpg_quest_get_from_conf(char *path, game_t *game, scene_t *scene)
{
    quest_t *quest = malloc(sizeof(quest_t));
    json_object_t *js = json_create_from_file((char *) path);

    if (quest == NULL || js == NULL)
        return (NULL);
    quest->state = 0;
    quest->actual_step = 0;
    get_int_from_conf(js, &quest->reward, "reward_item");
    if ((quest->name = get_str_from_conf(js, "name")) == NULL) {
        rpg_destroy_quest(quest);
        return (NULL);
    }
    rpg_quest_load_step_from_conf(js, game, scene);
    //FONCTION LOAD QUEST FROM SAVE
    json_object_destroy(js);
    return (quest);
}