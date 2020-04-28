/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_button_init.c
*/

#include "my_game.h"
#include "components/pnj/pnj.h"

static const char *path = "templates/menu/continuedialog.png";

static void rpg_pnj_init_button_box(game_object_t *object, sfVector2f pos)
{
    object->box.height = 126;
    object->box.width = 267;
    object->box.top = pos.y;
    object->box.left = pos.x;
}

game_object_t *rpg_pnj_init_button_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *button = NULL;
    sfVector2f pos = {1600, 900};

    button = create_game_object(last, (char *) path, pos, DIALOG_BUTTON);
    if (button == NULL)
        return (NULL);
    button->draw = NULL;
    rpg_pnj_init_button_box(button, pos);
    button->z_index = scene->z_index_deepth;
    button->update = &rpg_pnj_button_update;
    button->callback = &rpg_pnj_button_callback;
    return (button);
}