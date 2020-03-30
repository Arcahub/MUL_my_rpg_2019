/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** default_event
*/

#include "my_game/event.h"
#include "my_game.h"

void close_scene(sfEvent event, game_t *game, scene_t *scene, sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void is_click_on_object(sfEvent event, game_t *game, scene_t *scene, sfRenderWindow *window)
{
    game_object_t *object = scene->objects_list;
    sfMouseButtonEvent mouse_button = event.mouseButton;
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window->window);
    int x = pos.x;
    int y = pos.y;

    if (mouse_button.button != sfMouseLeft)
        return;
    for (; object; object = object->next) {
        if (object->callback != NULL && sfIntRect_contains(&object->box, x, y))
            object->callback(object, scene);
    }
}