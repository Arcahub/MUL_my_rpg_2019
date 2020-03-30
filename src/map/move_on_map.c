/*
** EPITECH PROJECT, 2019
** test_rpg
** File description:
** move_on_map.c
*/

#include "my_rpg.h"

void set_ship_angle(game_object_t *object, sfVector2f move)
{
    if (move.x == 10) {
        sfSprite_setRotation(object->sprite, -90);
        sfSprite_setPosition(object->sprite, (sfVector2f) \
        {WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 + 100});
    }
    if (move.x == -10) {
        sfSprite_setRotation(object->sprite, 90);
        sfSprite_setPosition(object->sprite, (sfVector2f) \
        {WINDOW_WIDTH / 2 + 100, WINDOW_HEIGHT / 2 - 100});
    }
    if (move.y == 10) {
        sfSprite_setRotation(object->sprite, 0);
        sfSprite_setPosition(object->sprite, (sfVector2f) \
        {WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 100});
    }
    if (move.y == -10) {
        sfSprite_setRotation(object->sprite, 180);
        sfSprite_setPosition(object->sprite, (sfVector2f) \
        {WINDOW_WIDTH / 2 + 100, WINDOW_HEIGHT / 2 + 100});
    }
}

game_object_t *move_on_map(scene_t *scene, sfVector2f move)
{
    game_object_t *tmp = NULL;

    for (tmp = scene->objects_list; tmp; tmp = tmp->next)
        if (tmp->type == DECOR) {
            sfSprite_move(tmp->sprite, move);
            tmp->pos.x += move.x;
            tmp->pos.y += move.y;
        }
    tmp = scene->objects_list;
    for (tmp = scene->objects_list; tmp; tmp = tmp->next)
        if (tmp->type == SPACESHIP)
            set_ship_angle(tmp, move);
    return (scene->objects_list);
}