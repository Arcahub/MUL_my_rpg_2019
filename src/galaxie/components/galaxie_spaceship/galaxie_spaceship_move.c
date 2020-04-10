/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_spaceship_move
*/

#include "galaxie/galaxie_spaceship.h"

void galaxie_spaceship_move(game_object_t *object, scene_t *scene)
{
    sfView *view = (sfView *) sfRenderWindow_getView(scene->window);
    sfVector2f pos = {0, 0};

    if (view == NULL)
        return;
    object->move.x *= 5;
    object->move.y *= 5;
    move_object(object);
    pos.x = object->pos.x + object->box.width / 2;
    pos.y = object->pos.y + object->box.height / 2;
    sfView_setCenter(view, pos);
    sfRenderWindow_setView(scene->window, view);
    object->move = (sfVector2f) {0, 0};
}