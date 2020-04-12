/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rpg_ennemy_update.c
*/

#include "my_game.h"
#include "my.h"
#include "const.h"
#include "components/fight_handler/ennemy.h"
#include <stdlib.h>

bool rpg_ennemy_update(game_object_t *object, scene_t *scene)
{
    ennemy_t *ennemy = (ennemy_t *) object->extend;
    char *tmp1 = NULL;
    char *tmp2 = NULL;

    if (ennemy == NULL)
        return (false);
    if (ennemy->in_fight == 1) {
        tmp1 = my_strcat("Ennemy's life: ", my_nbr_to_str(ennemy->hp));
        tmp2 = my_strcat("Ennemy's shield: ", my_nbr_to_str(ennemy->shield));
        if (tmp1 == NULL || tmp2 == NULL)
            return (false);
        sfText_setString(ennemy->hp_text, tmp1);
        sfText_setString(ennemy->shield_text, tmp2);
        free(tmp1);
        free(tmp2);
    }
    return (true);
}