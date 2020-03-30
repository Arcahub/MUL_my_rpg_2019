/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** infos
*/

#include "my_rpg.h"
#include <stdlib.h>

void draw_info_menu(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfText *text = init_text("HOW TO PLAY", 450, 100, (char *) FONT_PATH);

    sfText_setCharacterSize(text, 100);
    display_scene(scene, window);
    draw_cursor(game->cursor, scene->window);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
}

game_object_t *create_infos_objects2(game_object_t *object)
{
    object = create_game_object(object, (char *)TITLE_PATH, (sfVector2f) \
    {0, 0}, DECOR);
    init_appearing_object(object);
    object->update = &update_parallax_position;
    object = create_animated_object(object, (char *)INFOS_CONTENT_PATH, \
    (sfVector2f) {0, 0}, (sfIntRect **)INFOS_CONTENT_FRAME_KEYS);
    init_appearing_object(object);
    object->update = &update_appearing_object;
    object->type = INFO;
    return (object);
}

game_object_t *create_infos_objects(void)
{
    game_object_t *object = NULL;

    object = create_game_object(object, (char *) ARROW_RIGHT_PATH, \
    (sfVector2f) {INFOS_ARROW_RIGHT_X, INFOS_ARROW_Y}, DECOR);
    object->callback = &infos_right_arrow_function;
    object = create_game_object(object, (char *) ARROW_LEFT_PATH, (sfVector2f) \
    {INFOS_ARROW_LEFT_X, INFOS_ARROW_Y}, DECOR);
    object->callback = &infos_left_arrow_function;
    object = create_text_button(object, (char *) \
    RETURN_BUTTON_PATH, (sfVector2f) {RETURN_BUTTON_X, RETURN_BUTTON_Y + 75});
    object->callback = &return_button_function;
    return (create_infos_objects2(object));
}

scene_t *create_infos_menu(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->background_color = sfBlack;
    scene->handle_event = &handle_event_infos;
    scene->z_index_deepth = 0;
    scene->objects_list = create_infos_objects();
    return (scene);
}