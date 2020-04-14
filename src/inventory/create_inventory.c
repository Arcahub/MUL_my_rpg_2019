/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_inventory.c
*/

#include "my_json.h"
#include "components/get_from_config.h"
#include "my_game.h"
#include "item/inventory.h"

bool rpg_update_inventory(game_object_t *object, scene_t *scene)
{
    inventory_t *tmp = tmp = (inventory_t *) object->extend;
    sfVector2f tmp2 = {275, 250};

    if (object->state == 0)
        return (true);
    for (int x = 0, y = 0; tmp; tmp = tmp->next, x++) {
        if (x == 11) {
            x = 0;
            y++;
        }
        tmp2.x = 275 + (x * 60);
        tmp2.y = 250 + (y * 60) - 50;
        tmp->box.height = 50;
        tmp->box.width = 50;
        tmp->box.left = tmp2.x;
        tmp->box.top = tmp2.y;
        sfSprite_setPosition(tmp->sprite, tmp2);
    }
    return (true);
}

void rpg_inventory_get_click_on_item(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);
    inventory_t *tmp = NULL;
    int x = pos.x;
    int y = pos.y;

    for (tmp = (inventory_t *) object->extend; tmp; tmp = tmp->next) {
        if (sfIntRect_contains(&tmp->box, x, y)) {
            tmp->selected = 1;
        } else
            tmp->selected = 0;
    }
}

void rpg_inventory_draw(sfRenderWindow *window, game_object_t *object)
{
    inventory_t *tmp = NULL;

    if (object->state == 0)
        return;
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    for (tmp = (inventory_t *) object->extend; tmp; tmp = tmp->next)
        if (tmp->texture != NULL && tmp->sprite != NULL \
        && tmp->selected == 1) {
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
            sfRenderWindow_drawText(window, tmp->text[0], NULL);
            sfRenderWindow_drawText(window, tmp->text[1], NULL);
            sfRenderWindow_drawText(window, tmp->text[2], NULL);
        } else if (tmp->texture != NULL && tmp->sprite != NULL)
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
}

game_object_t *rpg_inventory_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), (sfVector2f) {0, -50}, INVENTORY);

    if (object == NULL)
        return (NULL);
    object->draw = &rpg_inventory_draw;
    object->callback = &rpg_inventory_get_click_on_item;
    object->update = &rpg_update_inventory;
    object->box.height = 600;
    object->box.width = 600;
    object->box.left = 250;
    object->box.top = 215;
    object->extend = (void *) rpg_inventory_add_item(NULL, 4, 0);
    object->extend = (void *) rpg_inventory_add_item((inventory_t *)
    object->extend, 4, 1);
    if (object == NULL || object->extend == NULL) {
        rpg_inventory_destroy(object->extend);
        destroy_game_object(scene, object);
        return (NULL);
    }
    return (object);
}