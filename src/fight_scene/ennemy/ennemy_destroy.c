/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_ennemy.c
*/

#include "fight_scene/ennemy.h"
#include <stdlib.h>

void rpg_ennemy_destroy(void *ptr)
{
    ennemy_t *ennemy = ptr;

    if (ptr == NULL)
    if (ennemy == NULL)
        return;
    ennemy = (ennemy_t *) ptr;
    if (!ennemy->name)
        free(ennemy->name);
    if (!ennemy->id)
        free(ennemy->id);
    if (!ennemy->name_text)
        sfText_destroy(ennemy->name_text);
    if (!ennemy->hp_text)
        sfText_destroy(ennemy->hp_text);
    if (!ennemy->shield_text)
        sfText_destroy(ennemy->shield_text);
    if (!ennemy)
        free(ennemy);
    free(ennemy);
}