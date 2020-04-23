/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** callback_pnj.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include "my.h"
#include "tmp_font.h"
#include <stdlib.h>

void rpg_pnj_quest_callback(game_object_t *object, scene_t *scene, pnj_t *pnj)
{
    if (scene->game->quest->state == UNTAKEN ||
    scene->game->quest->state == RESET) {
        rpg_pnj_open_dialog_give_quest(pnj, scene);
        return;
    } else if (scene->game->quest->state == TAKEN && \
    scene->game->quest->id == pnj->quest_id) {
        rpg_pnj_open_dialog_doing_quest(pnj, scene);
        return;
    }
    if (scene->game->quest->state == ACHIEVED  && \
    scene->game->quest->id == pnj->quest_id)
        rpg_pnj_open_dialog_quest_over(pnj, scene);
}