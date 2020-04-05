/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_key_pressed
*/

#include "my_rpg.h"
#include "galaxie/galaxie.h"
#include "in_game_menu/in_game_menu.h"

void rpg_galaxie_handle_move_on_map(game_t *game, sfKeyCode key, scene_t *scene)
{
    if (key == sfKeyRight)
        scene->objects_list = rpg_galaxie_move_on_map(scene, (sfVector2f) {-10, 0});
    if (key == sfKeyLeft)
        scene->objects_list = rpg_galaxie_move_on_map(scene, (sfVector2f) {10, 0});
    if (key == sfKeyUp)
        scene->objects_list = rpg_galaxie_move_on_map(scene, (sfVector2f) {0, 10});
    if (key == sfKeyDown)
        scene->objects_list = rpg_galaxie_move_on_map(scene, (sfVector2f) {0, -10});
}

void rpg_galaxie_handle_key_pressed(sfEvent event, game_t *game, scene_t *scene, sfRenderWindow *window)
{
    sfKeyCode key = event.key.code;

    if (key == sfKeyEscape)
        scene->display = rpg_in_game_menu_launch(game, scene);
    rpg_galaxie_handle_move_on_map(game, key, scene);
}