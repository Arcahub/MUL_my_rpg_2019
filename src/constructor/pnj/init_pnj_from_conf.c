/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_pnj_from_conf.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include "my_json.h"
#include "components/get_from_config.h"

static const char *path = "templates/menu/continuedialog.png";

void rpg_draw_pnj(sfRenderWindow *window, game_object_t *object)
{
    pnj_t *pnj = (pnj_t *) object->extend;

    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    if (pnj->draw_text == 1)
        sfRenderWindow_drawText(window, pnj->dialog_text, NULL);
}

static game_object_t *rpg_pnj_init_button(game_object_t *last)
{
    game_object_t *button = NULL;
    sfVector2f pos = {1600, 900};

    button = create_game_object(last, (char *) path, pos, DIALOG_BUTTON);
    if (button == NULL)
        return (NULL);
    button->box.height = 126;
    button->box.width = 267;
    button->box.top = pos.y;
    button->box.left = pos.x;
    button->draw = NULL;
    button->callback = &rpg_pnj_button_callback;
    return (button);
}

static game_object_t *rpg_pnj_init_box_and_pos(game_object_t *object,
sfVector2f pos)
{
    object->pos.x = pos.x;
    object->pos.y = pos.y;
    object->box.left = object->pos.x;
    object->box.top = object->pos.y;
    object->box.height = 50;
    object->box.width = 50;
    sfSprite_setPosition(object->sprite, object->pos);
    return (object);
}

game_object_t *rpg_pnj_init_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    sfVector2f pos = {0, 0};
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), pos, PNJ);

    if (object == NULL)
        return (NULL);
    object->extend = (void *)
    rpg_pnj_init_extend_from_conf(object, js, game, scene);
    object->free_extend = &rpg_pnj_destroy;
    if (!get_vector2f_from_conf(js, &pos, "pos") || 
    object->extend == NULL) {
        destroy_game_object(scene, object);
        return (NULL);
    }
    object->draw = &rpg_draw_pnj;
    object->update = &rpg_pnj_update;
    object->callback = &rpg_pnj_callback;
    object = rpg_pnj_init_box_and_pos(object, pos);
    object = rpg_pnj_init_button(object);
    return (object);
}