/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/fight_handler/fight_handler.h"
#include "spaceship/ship.h"
#include <stdlib.h>

static sfIntRect rpg_fight_handler_button_init_box(game_object_t *object)
{
    sfIntRect box = {0, 0, 0, 0};

    if (object == NULL)
        return (box);
    box.left = object->pos.x;
    box.top = object->pos.y;
    box.height = 100;
    box.width = 200;
    return (box);
}

static fight_handler_t *rpg_fight_handler_init_button(fight_handler_t *handler, scene_t *scene)
{
    game_object_t *button = create_game_object(NULL, "templates/attack.png", \
    (sfVector2f) {100, 400}, ATTACK_BUTTON);

    if (button == NULL)
        return (NULL);
    button->box = rpg_fight_handler_button_init_box(button);
    button = create_game_object(button, "templates/repair.png", \
    (sfVector2f) {100, 600}, REPAIR_BUTTON);
    if (button == NULL)
        return (NULL);
    button->box = rpg_fight_handler_button_init_box(button);
    button = create_game_object(button, "templates/dodge.png", \
    (sfVector2f) {100, 800}, DODGE_BUTTON);
    if (button == NULL)
        return (NULL);
    button->box = rpg_fight_handler_button_init_box(button);
    handler->button = button;
    return (handler);
}

static fight_handler_t *rpg_fight_handler_init_extend(game_object_t *object, scene_t *scene)
{
    fight_handler_t *handler = malloc(sizeof(fight_handler_t));

    if (handler == NULL || object == NULL)
        return (NULL);
    handler->in_fight = 1;
    handler->player_turn = 1;
    handler->done = 0;
    handler->action_number = 3;
    handler->id = malloc(sizeof(action_id) * handler->action_number);
    if (handler->id == NULL)
        return (NULL);
    for (int x = 0; x != handler->action_number; x++)
        handler->id[x] = EMPTY;
    handler = rpg_fight_handler_init_button(handler, scene);
    return (handler);
}

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

game_object_t *rpg_fight_handler_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, \
    "templates/fight_handler.png", (sfVector2f) {0, 0}, FIGHT_HANDLER);

    if (object == NULL)
        return (NULL);
    object->update = &rpg_fight_handler_update;
    object->draw = &rpg_fight_handler_draw;
    object->callback = &rpg_fight_handler_callback;
    object->box.left = object->pos.x;
    object->box.top = object->pos.y;
    object->box.height = 1920;
    object->box.width = 1080;
    object->extend = (void *) rpg_fight_handler_init_extend(object, scene);
    if (object == NULL || object->extend == NULL) {
        rpg_fight_handler_free_extend((fight_handler_t *) object->extend);
        destroy_game_object(scene, object);
        return (NULL);
    }
    return (object);
}