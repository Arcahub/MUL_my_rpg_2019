/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_options_objects
*/

#include "my_rpg.h"
#include "options_menu/options_menu.h"

static game_object_t *rpg_options_create_object_list2(game_object_t *object)
{
    object = create_game_object(object, (char *) BAR_BACKGROUND_PATH, \
    (sfVector2f) {VOLUME_BAR_X, VOLUME_BAR_Y}, DECOR);
    init_appearing_object(object);
    object->update = &update_appearing_object;
    object = create_game_object(object, (char *)TITLE_PATH, (sfVector2f) \
    {0, 0}, DECOR);
    init_appearing_object(object);
    object->update = &rpg_main_menu_update_parallax_position;
    return (object);
}

game_object_t *rpg_options_create_object_list(void)
{
    game_object_t *object = NULL;

    object = create_animated_object(object, (char *)TITLE_UNDERLINE_PATH, \
    (sfVector2f) {TITLE_UNDERLINE_X, TITLE_UNDERLINE_Y}, \
    (sfIntRect **)TITLE_UNDERLINE_FRAME_KEYS);
    object->type = FLEUR;
    object = rpg_options_create_indicator(object, (char *)INDICATOR_PATH, \
    (sfVector2f) {INDICATOR_X, INDICATOR_Y});
    object = rpg_options_create_bar(object, (char *) BAR_PATH, \
    (sfVector2f) {VOLUME_BAR_X, VOLUME_BAR_Y});
    object->box = (sfIntRect) {VOLUME_BAR_X - BAR_BOX_OFFSET / 2, \
    VOLUME_BAR_Y, BAR_WIDTH, BAR_HEIGHT + BAR_BOX_OFFSET};
    object = create_text_button(object, (char *) \
    RETURN_BUTTON_PATH, (sfVector2f) {RETURN_BUTTON_X, RETURN_BUTTON_Y});
    object->callback = &return_button_function;
    return (rpg_options_create_object_list2(object));
}