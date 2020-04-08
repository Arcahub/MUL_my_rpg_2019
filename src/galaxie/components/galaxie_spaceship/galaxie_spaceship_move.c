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

    if (view == NULL)
        return;
    sfView_move(view, object->move);
    sfRenderWindow_setView(scene->window, view);
    move_object(object);
    object->move = (sfVector2f) {0, 0};
}