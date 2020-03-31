/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu_create_button
*/

#include "my_rpg.h"
#include "main_menu/main_menu.h"

game_object_t *rpg_main_menu_create_buttons(void)
{
    game_object_t *object = NULL;

    object = create_text_button(object, (char *)PLAY_BUTTON_PATH, \
    (sfVector2f) {PLAY_BUTTON_X, PLAY_BUTTON_Y});
    object->callback = &play_button_function;
    object = create_text_button(object, (char *)OPTION_BUTTON_PATH, \
    (sfVector2f) {OPTION_BUTTON_X, OPTION_BUTTON_Y});
    object->callback = &options_button_function;
    object = create_text_button(object, (char *)INFOS_BUTTON_PATH, \
    (sfVector2f) {INFOS_BUTTON_X, INFOS_BUTTON_Y});
    object->callback = &infos_button_function;
    object = create_text_button(object, (char *)EXIT_BUTTON_PATH, \
    (sfVector2f) {EXIT_BUTTON_X, EXIT_BUTTON_Y});
    object->callback = &exit_button_function;
    object = create_game_object(object, (char *) SHIPS_PATH, (sfVector2f) \
    {0, 0}, DECOR);
    init_appearing_object(object);
    object->update = &update_appearing_object;
    object = create_game_object(object, (char *)TITLE_PATH, \
    (sfVector2f) {0, 0}, DECOR);
    init_appearing_object(object);
    object->update = &rpg_main_menu_update_parallax_position;
    return (object);
}