/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_button_free_extend.c
*/

#include "my_game.h"
#include <stdlib.h>

void rpg_pnj_button_free_extend(void *pt)
{
    game_object_t *object = NULL;

    if (pt == NULL)
        return;
    object = (game_object_t *) pt;
    if (object->sprite != NULL && object->texture != NULL) {
        sfSprite_destroy(object->sprite);
        sfTexture_destroy(object->texture);
    }
    free(object);
}