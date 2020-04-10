/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_mini_map_update
*/

#include "galaxie/galaxie_minimap.h"
#include "galaxie/galaxie_background.h"

static void check_background_left(scene_t *scene, game_t *game,
galaxie_mini_map_t *map)
{
    bool is_background = false;
    game_object_t *tmp = scene->objects_list;
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(scene->window));

    pos.x -= 1.5 * game->window->width;
    for (; tmp; tmp = tmp->next)
        if (tmp->type == GALAXIE_BACKGROUND && sfIntRect_contains(&tmp->box,
        pos.x, pos.y))
            is_background = true;
    if (is_background == true)
        return;
    printf("2\n");
    tmp = galaxie_background_generate_col(scene->objects_list,
    map, (sfVector2f) {pos.x - game->window->width, pos.y}, 3);
    scene->objects_list = (tmp) ? tmp : scene->objects_list;
}

static void check_background_right(scene_t *scene, game_t *game,
galaxie_mini_map_t *map)
{
    bool is_background = false;
    game_object_t *tmp = scene->objects_list;
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(scene->window));

    pos.x += 1.5 * game->window->width;
    for (; tmp; tmp = tmp->next)
        if (tmp->type == GALAXIE_BACKGROUND && sfIntRect_contains(&tmp->box,
        pos.x, pos.y))
            is_background = true;
    if (is_background == true)
        return;
    printf("3\n");
    tmp = galaxie_background_generate_col(scene->objects_list,
    map, (sfVector2f) {pos.x, pos.y}, 3);
    scene->objects_list = (tmp) ? tmp : scene->objects_list;
}

static void check_background_bot(scene_t *scene, game_t *game,
galaxie_mini_map_t *map)
{
    bool is_background = false;
    game_object_t *tmp = scene->objects_list;
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(scene->window));

    pos.y += 1.5 * game->window->height;
    for (; tmp; tmp = tmp->next)
        if (tmp->type == GALAXIE_BACKGROUND && sfIntRect_contains(&tmp->box,
        pos.x, pos.y))
            is_background = true;
    if (is_background == true)
        return;
    printf("1\n");
    tmp = galaxie_background_generate_line(scene->objects_list,
    map,(sfVector2f) {pos.x, pos.y}, 3);
    scene->objects_list = (tmp) ? tmp : scene->objects_list;
}

static void check_background_top(scene_t *scene, game_t *game,
galaxie_mini_map_t *map)
{
    bool is_background = false;
    game_object_t *tmp = scene->objects_list;
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(scene->window));

    pos.y -= 1.5 * game->window->height;
    for (; tmp; tmp = tmp->next)
        if (tmp->type == GALAXIE_BACKGROUND && sfIntRect_contains(&tmp->box,
        pos.x, pos.y))
            is_background = true;
    if (is_background == true)
        return;
    printf("0\n");
    tmp = galaxie_background_generate_line(scene->objects_list,
    map, (sfVector2f) {pos.x, pos.y - game->window->height}, 3);
    scene->objects_list = (tmp) ? tmp : scene->objects_list;
}

bool galaxie_mini_map_update(game_object_t *object, scene_t *scene)
{
    galaxie_mini_map_t *map = object->extend;
    game_t *game = scene->game;

    check_background_left(scene, game, map);
    check_background_top(scene, game, map);
    check_background_bot(scene, game, map);
    check_background_right(scene, game, map);
    return (true);
}