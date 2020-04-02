/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_pnj.c
*/

#include "pnj/pnj.h"
#include "my_game.h"

pnj_t *rpg_init_pnj_extend(pnj_type type, char *path)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));

    if (pnj == NULL)
        return (NULL);
    pnj->type = type;
    return (pnj);
}

game_object_t *rpg_pnj_create(game_object_t *last, char *settings_path, \
char *sprite_path, pnj_type type)
{
    game_object_t *object = create_game_object(last, sprite_path, \
    (sfVector2f) {0, 0}, PNJ);

    if (object == NULL)
        return (NULL);
    object->extend = (pnj_t *) rpg_init_pnj_extend(type, settings_path);
    return (object);
}