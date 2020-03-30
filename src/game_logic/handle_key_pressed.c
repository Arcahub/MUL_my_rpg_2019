/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_key_pressed
*/

#include "my_rpg.h"

void handle_move_on_map(game_t *game, sfKeyCode key, scene_t *scene)
{
    if (key == sfKeyRight)
        scene->objects_list = move_on_map(scene, (sfVector2f) {-10, 0});
    if (key == sfKeyLeft)
        scene->objects_list = move_on_map(scene, (sfVector2f) {10, 0});
    if (key == sfKeyUp)
        scene->objects_list = move_on_map(scene, (sfVector2f) {0, 10});
    if (key == sfKeyDown)
        scene->objects_list = move_on_map(scene, (sfVector2f) {0, -10});
}

void handle_key_pressed_game(game_t *game, sfKeyCode key, scene_t *scene)
{
    if (key == sfKeyEscape)
        scene->display = do_in_game_menu(game, scene);
    handle_move_on_map(game, key, scene);
}