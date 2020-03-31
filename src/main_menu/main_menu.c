/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main_menu
*/

#include "my_rpg.h"
#include "main_menu/main_menu.h"
#include <stdlib.h>

bool rpg_main_menu_update_parallax_position(game_object_t *object, scene_t *scene)
{
    sfSprite_move(object->sprite, (sfVector2f) {-2, 0});
    object->pos = sfSprite_getPosition(object->sprite);
    if (object->pos.x <= -1920)
        sfSprite_setPosition(object->sprite, (sfVector2f) {0, 0});
    return (update_appearing_object(object, scene));
}

void rpg_main_menu_draw_scene(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfText *text = init_text("Space My RPG !", 400, 100, (char *) FONT_PATH);

    sfText_setCharacterSize(text, 100);
    display_scene(scene, window);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    sfFont_destroy((sfFont *) sfText_getFont(text));
    sfText_destroy(text);
}

scene_t *rpg_main_menu_create_scene(game_t *game)
{
    scene_t *scene = create_empty_scene(game->window->window);

    if (scene == NULL)
        return (NULL);
    scene->objects_list = rpg_main_menu_create_buttons();
    scene->update_scene = &update_scene;
    scene->display = MAIN_MENU_SCENE;
    rpg_main_menu_bind_event(scene);
    return (scene);
}