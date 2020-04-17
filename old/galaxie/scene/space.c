/*
** EPITECH PROJECT, 2019
** test_rpg
** File description:
** space.c
*/

#include "my_rpg.h"
#include "galaxie/galaxie.h"

void draw_space_background(sfRenderWindow *window, game_object_t *object)
{
    if (object->pos.x > -2880 && object->pos.x < 2880 && \
    object->pos.y > -1620 && object->pos.y < 1620)
        sfRenderWindow_drawSprite(window, object->sprite, NULL);
}

game_object_t *rpg_galaxie_generate_space(void)
{
    game_object_t *object = rpg_galaxie_create_ship();
    int x_img_space = 1920 * - 5;
    int y_img_space = 1080 * - 5;

    for (int y = 0, x = 0; y != SIZE_Y_SPACE; x++, x_img_space += 1920) {
        if (x == SIZE_X_SPACE) {
            x_img_space = 1920 * - 5;
            x = 0;
            y++;
            y_img_space += 1080;
        }
        object = create_game_object(object, (char *)BACKGROUND_SPACE, \
        (sfVector2f) {x_img_space, y_img_space}, DECOR);
        object->draw = &draw_space_background;
        if (object == NULL)
            return (NULL);
    }
    return (object);
}