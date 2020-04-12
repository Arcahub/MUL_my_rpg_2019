/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_handler_callback.c
*/

#include "my_game.h"
#include "components/fight_handler/fight_handler.h"

void rpg_fight_handler_callback(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
    fight_handler_t *handler = (fight_handler_t *) object->extend;

    if (handler->done == handler->action_number || handler->in_fight == 0)
        return;
    for (game_object_t *tmp = handler->button; tmp; tmp = tmp->next) {
        if (sfIntRect_contains(&tmp->box, pos.x, pos.y) && \
        tmp->type == ATTACK_BUTTON)
            handler->id[handler->done] = ATTACK;
        if (sfIntRect_contains(&tmp->box, pos.x, pos.y) && \
        tmp->type == REPAIR_BUTTON && \
        rpg_fight_handler_spaceship_get_repair_statue(scene) >= 3)
            handler->id[handler->done] = REPAIR;
        if (sfIntRect_contains(&tmp->box, pos.x, pos.y) && \
        tmp->type == DODGE_BUTTON)
            handler->id[handler->done] = DODGE;
    }
    if (handler->id[handler->done] == EMPTY)
        return;
    handler->done++;
}