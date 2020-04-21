/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** callback_pnj.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"

void rpg_pnj_callback(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
    pnj_t *pnj = (pnj_t *) object->extend;
}