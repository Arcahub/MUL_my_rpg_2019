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

bool update_inventory(game_object_t *object, scene_t *scene)
{
    inventory_t *tmp = NULL;
    sfVector2f tmp2 = {275, 250};
    int x = 0;
    int y = 0;

    for (tmp = (inventory_t *) object->extend; tmp; tmp = tmp->next, x++) {
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

void get_click_on_item(game_object_t *object, scene_t *scene)
{
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

void draw_inventory(sfRenderWindow *window, game_object_t *object)
{
    inventory_t *tmp = NULL;
    
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    for (tmp = (inventory_t *) object->extend; tmp; tmp = tmp->next)
        if (tmp->texture != NULL || tmp->sprite != NULL)
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
}

game_object_t *rpg_inventory_create(game_object_t *last, char *path)
{
    game_object_t *object = create_game_object(last, path, (sfVector2f) {0, -50}, INVENTORY);

    if (object == NULL)
        return (NULL);
    object->draw = &draw_inventory;
    object->callback = &get_click_on_item;
    object->update = &update_inventory;
    object->extend = (void *) rpg_inventory_add_item(NULL, "config/item/basic_canon.json", 4, 0);
    if (object->extend == NULL)
        exit(0);
    return (object);
}