/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** GG_menu
*/

#include "my_rpg.h"
#include <stdlib.h>

void restart_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = GALAXIE_SCENE;
}

game_object_t *create_end_menu_objects(void)
{
    game_object_t *object = NULL;

    object = create_animated_object(object, (char *)GG_TOP_PATH, \
    (sfVector2f) {GG_TOP_X, GG_TOP_Y}, (sfIntRect **)GG_TOP_FRAME_KEYS);
    object->type = FLEUR;
    object = create_animated_object(object, (char *)GG_BOT_PATH, \
    (sfVector2f) {GG_BOT_X, GG_BOT_Y}, (sfIntRect **)GG_BOT_FRAME_KEYS);
    object->type = FLEUR;
    object = create_text_button(object, (char *)MAIN_MENU_BUTTON_PATH, \
    (sfVector2f) {MAIN_MENU_BUTTON_X, GG_MAIN_MENU_BUTTON_Y});
    object->callback = &main_menu_button_function;
    object = create_text_button(object, (char *)RESTART_PATH, \
    (sfVector2f) {RESTART_X, RESTART_Y});
    object->callback = &restart_button_function;
    object = create_game_object(object, (char *)TITLE_PATH, \
    (sfVector2f) {0, 0}, DECOR);
    init_appearing_object(object);
    object->update = update_appearing_object;
    return (object);
}

void rpg_end_menu_draw_scene(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    display_scene(scene, window);
    sfRenderWindow_display(window);
}

scene_t *rpg_end_menu_create_scene(game_t *game)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->objects_list = create_end_menu_objects();
    scene->display = END_SCENE;
    return (scene);
}

int rpg_end_menu_loop(game_t *game, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    scene_t *scene = rpg_end_menu_create_scene(game);
    scene_index display = END_SCENE;

    if (scene == NULL)
        scene->display = -1;
    scene->window = window;
    while (sfRenderWindow_isOpen(window) && scene->display == END_SCENE) {
        handle_scene_event(scene, game, window);
        handle_framerate(clock, scene, game);
        rpg_end_menu_draw_scene(scene, game, window);
    }
    disappear_scene(scene, window, clock, game);
    sfClock_destroy(clock);
    display = scene->display;
    destroy_scene(scene);
    return (display);
}