/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_ennemy.c
*/

#include "components/fight_handler/ennemy.h"
#include <stdlib.h>

void rpg_ennemy_destroy(void *ptr)
{
    ennemy_t *ennemy = NULL;

    if (ptr != NULL)
        ennemy = (ennemy_t *) ptr;
    if (ennemy == NULL)
        return;
    if (!ennemy->name)
        free(ennemy->name);
    if (!ennemy->id)
        free(ennemy->id);
    if (!ennemy)
        free(ennemy);
}