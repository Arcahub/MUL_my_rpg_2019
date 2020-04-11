/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_galaxie_background
*/

#include "galaxie/galaxie_background.h"
#include "galaxie/galaxie_minimap.h"
#define ABS(X) ((X<0)?(-X):(X))

bool galaxie_background_update(game_object_t *object, scene_t *scene)
{
    sfVector2f range = {0, 0};
    galaxie_mini_map_t *map = object->extend;
    sfVector2f center = sfView_getCenter(map->view);

    range.x = object->pos.x - center.x;
    range.y = object->pos.y - center.y;
    if (ABS(range.x) > 1920 * 4)
        object->pos.x += 1920;
    else if (ABS(range.x) < 1920 * 3)
        object->pos.x -= 1920;
    else {
        if (ABS(range.y) > 1080 * 4)
            object->pos.y += 1080;
        else if (ABS(range.y) < 1080 * 3)
            object->pos.y -= 1080;
    }
    sfSprite_setPosition(object->sprite, object->pos);
    return (true);
}

game_object_t *create_galaxie_background(game_object_t *last,
galaxie_mini_map_t *map, sfVector2f pos)
{
    game_object_t *object = create_game_object(last, map->background_path, pos,
    GALAXIE_BACKGROUND);

    if (object == NULL)
        return (NULL);
    object->extend = map;
    object->update = &galaxie_background_update;
    return (object);
}