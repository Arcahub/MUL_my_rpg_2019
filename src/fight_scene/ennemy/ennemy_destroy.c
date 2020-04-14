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

    if (ennemy == NULL)
        return;
    if (!ennemy->name)
        free(ennemy->name);
    if (!ennemy->id)
        free(ennemy->id);
    free(ennemy);
}