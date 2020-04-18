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

void free_step(step_t *step)
{
    if (step == NULL)
        return;
    if (step->description)
        free(step->description);
    if (step->fight_scene)
        free(step->fight_scene);
    free(step);
}

void rpg_destroy_quest(quest_t *quest)
{
    step_t *tmp = NULL;
    step_t *step = NULL;

    if (quest == NULL)
        return;
    if (quest->name != NULL)
        free(quest->name);
    if (quest->step != NULL)
        step = quest->step;
        for (; step; step = tmp) {
            tmp = step->next;
            free_step(step);
        }
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
    if (!get_int_from_conf(js, (int *) &quest->reward_item, "reward_item") ||
    !get_int_from_conf(js, &quest->reward_money, "reward_money") ||
    !get_int_from_conf(js, (int *) &quest->id, "id") ||
    !get_int_from_conf(js, &quest->reward_item_number, "reward_item_number") ||
    (quest->name = get_str_from_conf(js, "name")) == NULL) {
        rpg_destroy_quest(quest);
        return (NULL);
    }   
    rpg_quest_load_step_from_conf(js, game, scene);
    json_object_destroy(js);
    return (quest);
}