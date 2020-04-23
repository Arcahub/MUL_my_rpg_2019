/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_button_init.c
*/

#include "my_game.h"
#include "components/pnj/pnj.h"

static const char *path = "templates/menu/continuedialog.png";
static const char *background_path = "templates/pnj_button_bg.jpg";

static game_object_t *rpg_pnj_init_button_background(void)
{
    sfVector2f pos = {0, 880};
    game_object_t *obj = create_game_object(NULL, (char *) background_path, \
    pos, DECOR);

    if (obj == NULL)
        return (NULL);
    obj->draw = NULL;
    return (obj);
}

static void rpg_pnj_init_button_box(game_object_t *object, sfVector2f pos)
{
    object->box.height = 126;
    object->box.width = 267;
    object->box.top = pos.y;
    object->box.left = pos.x;
}

game_object_t *rpg_pnj_init_button(game_object_t *last)
{
    game_object_t *button = NULL;
    sfVector2f pos = {1600, 900};
    static int created = 0;

    if (created == 1)
        return (last);
    button = create_game_object(last, (char *) path, pos, DIALOG_BUTTON);
    if (button == NULL)
        return (NULL);
    button->draw = NULL;
    rpg_pnj_init_button_box(button, pos);
    button->update = &rpg_pnj_button_update;
    button->callback = &rpg_pnj_button_callback;
    button->free_extend = &rpg_pnj_button_free_extend;
    if ((button->extend = (void *) rpg_pnj_init_button_background()) == NULL)
        return (NULL);
    created = 1;
    return (button);
}