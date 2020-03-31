/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** in_game_menu
*/

#include "my_rpg.h"
#include "my_game.h"
#include "in_game_menu/in_game_menu.h"
#include "my_game/framerate.h"
#include <stdlib.h>

game_object_t *rpg_in_game_menu_create_objects_list(void)
{
    game_object_t *object = NULL;

    object = create_text_button(object, (char *)CONTINUE_BUTTON_PATH, \
    (sfVector2f) {CONTINUE_BUTTON_X, CONTINUE_BUTTON_Y});
    object->callback = &play_button_function;
    object = create_text_button(object, (char *)INFOS_BUTTON_PATH, \
    (sfVector2f) {INFOS_BUTTON_X, INFOS_BUTTON_Y});
    object->callback = &infos_button_function;
    object = create_text_button(object, (char *)OPTION_BUTTON_PATH, \
    (sfVector2f) {OPTION_BUTTON_X, OPTION_BUTTON_Y});
    object->callback = &options_button_function;
    object = create_text_button(object, (char *)MAIN_MENU_BUTTON_PATH, \
    (sfVector2f) {MAIN_MENU_BUTTON_X, MAIN_MENU_BUTTON_Y});
    object->callback = &main_menu_button_function;
    object = create_game_object(object, (char *) SHIPS_PATH, (sfVector2f) \
    {0, 0}, DECOR);
    init_appearing_object(object);
    object->update = &update_appearing_object;
    object = create_game_object(object, (char *)TITLE_PATH, (sfVector2f) \
    {0, 0}, DECOR);
    init_appearing_object(object);
    object->update = &rpg_main_menu_update_parallax_position;
    return (object);
}

void rpg_in_game_menu_return_to_game(sfEvent event, game_t *game, scene_t *scene, sfRenderWindow *window)
{
    if (event.key.code == sfKeyEscape)
        scene->display = GALAXIE_SCENE;
}

void rpg_in_game_menu_bind_event(scene_t *scene)
{
    bind_event(scene, sfEvtClosed, &close_scene);
    bind_event(scene, sfEvtMouseButtonPressed, &is_click_on_object);
    bind_event(scene, sfEvtKeyPressed, &rpg_in_game_menu_return_to_game);
}

scene_t *rpg_in_game_menu_create_scene(game_t *game)
{
    scene_t *scene = create_empty_scene(game->window->window);

    if (scene == NULL)
        return (NULL);
    scene->objects_list = rpg_in_game_menu_create_objects_list();
    scene->display = IN_GAME_MENU_SCENE;
    rpg_in_game_menu_bind_event(scene);
    return (scene);
}

void rpg_in_game_menu_close_scene(scene_t *scene, sfRenderWindow *window, scene_t *last, \
game_t *game)
{
    static float frame = 0.0;
    sfClock *clock = sfClock_create();
    static float accumulator = 0.0;
    bool is_closed = false;

    while (!is_closed) {
        frame = sfClock_getElapsedTime(clock).microseconds / SECOND_IN_MICRO;
        sfClock_restart(clock);
        if (frame > MAX_FRAME_RANGE)
            frame = MAX_FRAME_RANGE;
        accumulator += frame;
        while (accumulator >= DELAY_BETWEEN_UPDATE && is_closed == false) {
            is_closed = disappear_scene_objects(scene);
            accumulator -= DELAY_BETWEEN_UPDATE;
        }
        display_scene(last, window);
        draw_objects(scene->objects_list, window, 0);
        draw_cursor(game->cursor, window);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(clock);
}

int rpg_in_game_menu_launch(game_t *game, scene_t *scene)
{
    int display = IN_GAME_MENU_SCENE;

    while (display != MAIN_MENU_SCENE && display != GALAXIE_SCENE && \
    display != -1 && sfRenderWindow_isOpen(game->window->window)) {
        if (display != IN_GAME_MENU_SCENE) {
            display = game->scene_loop[display](game, game->window->window);
            display = (display == MAIN_MENU_SCENE) ? \
            IN_GAME_MENU_SCENE : display;
        } else
            display = rpg_in_game_menu_loop(game, game->window->window, scene);
    }
    return (display);
}

void rpg_in_game_menu_launch_key(sfEvent event, game_t *game, scene_t *scene, sfRenderWindow *window)
{
    sfKeyCode key = event.key.code;

    if (key == sfKeyEscape)
        scene->display = rpg_in_game_menu_launch(game, scene);
}