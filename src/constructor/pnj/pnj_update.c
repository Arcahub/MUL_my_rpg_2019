/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_update.c
*/

#include "my_game.h"
#include "components/pnj/pnj.h"

bool rpg_pnj_update(game_object_t *object, scene_t *scene)
{
    pnj_t *pnj = (pnj_t *) object->extend;
    game_object_t *tmp = scene->objects_list;
    
    for (; tmp && tmp->type != DIALOG_BUTTON; tmp = tmp->next);
    if (tmp->type != DIALOG_BUTTON)
        return (true);
    if (pnj->draw_text == 0)
        tmp->draw = NULL;
    else
        tmp->draw = &draw_object;
    return (true);
}