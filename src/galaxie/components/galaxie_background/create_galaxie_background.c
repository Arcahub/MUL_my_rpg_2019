/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_galaxie_background
*/

#include "galaxie/galaxie_background.h"
#include "galaxie/galaxie_minimap.h"

game_object_t *create_galaxie_background(game_object_t *last,
galaxie_mini_map_t *map, sfVector2f pos)
{
    game_object_t *object = create_game_object(last, map->background_path, pos,
    GALAXIE_BACKGROUND);

    if (object == NULL)
        return (NULL);
    printf("%f, %f\n", pos.x, pos.y);
    object->box = (sfIntRect) {pos.x, pos.y, 1920, 1080};
    return (object);
}