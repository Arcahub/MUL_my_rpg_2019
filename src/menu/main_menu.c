/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main_menu
*/

#include "my_rpg.h"
#include <stdlib.h>

bool update_parallax_position(game_object_t *object, scene_t *scene)
{
    sfSprite *sprite = (sfSprite *) object->extend;

    sfSprite_move(object->sprite, (sfVector2f) {-2, 0});
    object->pos = sfSprite_getPosition(object->sprite);
    if (object->pos.x <= -1920)
        sfSprite_setPosition(object->sprite, (sfVector2f) {0, 0});
    return (update_appearing_object(object, scene));
}

game_object_t *create_main_menu_buttons(void)
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
    object->update = &update_parallax_position;
    return (object);
}

void draw_main_menu(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfText *text = init_text("Space My RPG !", 400, 100, (char *) FONT_PATH);

    sfText_setCharacterSize(text, 100);
    display_scene(scene, window);
    draw_cursor(game->cursor, scene->window);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
}

scene_t *create_main_menu(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = sfBlack;
    scene->handle_event = &handle_event_main_menu;
    scene->z_index_deepth = 0;
    scene->objects_list = create_main_menu_buttons();
    return (scene);
}