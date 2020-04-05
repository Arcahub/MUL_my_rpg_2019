/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_options_objects
*/

#include "my_rpg.h"
#include "options_menu/options_menu.h"

game_object_t *rpg_options_create_object_list(void)
{
    game_object_t *object = NULL;

    object->box = (sfIntRect) {VOLUME_BAR_X - BAR_BOX_OFFSET / 2, \
    VOLUME_BAR_Y, BAR_WIDTH, BAR_HEIGHT + BAR_BOX_OFFSET};
    object = create_text_button(object, (char *) \
    RETURN_BUTTON_PATH, (sfVector2f) {RETURN_BUTTON_X, RETURN_BUTTON_Y});
    object->callback = &return_button_function;
    return (object);
}