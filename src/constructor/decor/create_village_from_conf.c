/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_village_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "game_object.h"
#include "get_from_config.h"
#include "village_decor_constructor.h"

game_object_t *generate_tile(game_object_t *last, int id, int x, int y)
{
    game_object_t *tile = NULL;

    tile = create_game_object(last, TILE_PATH[id],
    (sfVector2f) {x , y}, TILE_MAP);
}

game_object_t *generate_map_line(game_object_t *last, json_array_t *arr,
int height, int width)
{
    game_object_t *tmp = NULL;

    for (int i = 0; i < arr->elem_count; i++) {
        if (arr->array[i]->value_type == INT) {
            tmp = generate_tile(last, *((int *) arr->array[i]->value),
            height, width + i);
            last = (tmp) ? tmp : last;
        }
    }
    return (last);
}

game_object_t *create_village(game_object_t *last, json_object_t *js,
game_t *game, scene_t *scene)
{
    json_value_t *value = NULL;
    json_array_t *arr = NULL;
    int tile_height = 0;
    int tile_width = 0;

    if (!get_int_from_conf(js, &tile_height, "tile_height") ||
    !get_int_from_conf(js, &tile_width, "tile_width"))
        return (NULL);
    value = json_get_element_by_key(js, "map");
    if (!value || value->value_type != ARRAY)
        return (NULL);
    arr = value->value;
    for (int i = 0; i < arr->elem_count; i++) {
        if (arr->array[i]->value_type == ARRAY)
            generate_map_line(last, arr->array[i]->value,
            tile_height * i, tile_width);
    }
    return (NULL);
}