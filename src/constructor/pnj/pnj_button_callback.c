/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_button_callback.c
*/

#include "my_game.h"
#include "components/pnj/pnj.h"
#include "components/quest/quest.h"
#include "tmp_font.h"
#include <stdlib.h>
#include "my.h"

void rpg_pnj_button_callback(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *) pt;
    game_object_t *tmp_obj = scene->objects_list;
    pnj_t *pnj = NULL;
    dialog_t *tmp = NULL;

    for (; tmp_obj && tmp_obj->type != PNJ; tmp_obj = tmp_obj->next);
    if (tmp_obj->type != PNJ)
        return;
    pnj = (pnj_t *) tmp_obj->extend;
    tmp = pnj->dialog;
    if (pnj->quest_statue == GET_QUEST) {
        rpg_dialog_advance_step(pnj, scene, tmp);
    } else if (pnj->quest_statue == GIVE_BACK_QUEST) {
        validate_quest(scene->game, scene, scene->game->quest);
        pnj->draw_text = 0;
    } else
        pnj->draw_text = 0;
}