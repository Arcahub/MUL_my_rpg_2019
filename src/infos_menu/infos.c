/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** infos
*/

#include "my_rpg.h"
#include "general_event.h"
#include <stdlib.h>

void rpg_infos_draw_scene(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfText *text = init_text("HOW TO PLAY", 450, 100, (char *) FONT_PATH);

    sfText_setCharacterSize(text, 100);
    display_scene(scene, window);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    sfFont_destroy((sfFont *) sfText_getFont(text));
    sfText_destroy(text);
}

game_object_t *rpg_infos_create_objects_list2(game_object_t *object)
{
    object = create_game_object(object, (char *)TITLE_PATH, (sfVector2f) \
    {0, 0}, DECOR);
    init_appearing_object(object);
    object->update = &rpg_main_menu_update_parallax_position;
    return (object);
}

game_object_t *rpg_infos_create_objects_list(void)
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
    return (rpg_infos_create_objects_list2(object));
}

void rpg_infos_bind_event(scene_t *scene)
{
    bind_event(scene, sfEvtClosed, &close_scene);
    bind_event(scene, sfEvtMouseButtonPressed, &is_click_on_object);
    bind_event(scene, sfEvtKeyPressed, &return_to_main_menu);
}

scene_t *rpg_infos_create_scene(game_t *game)
{
    scene_t *scene = create_empty_scene(game->window->window);

    if (scene == NULL)
        return (NULL);
    scene->objects_list = rpg_infos_create_objects_list();
    rpg_infos_bind_event(scene);
    return (scene);
}