/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_update.c
*/

#include "my_game.h"
#include "components/pnj/pnj.h"
#include "components/quest/quest.h"

void rpg_dialog_advance_step(pnj_t *pnj, scene_t *scene, dialog_t *dialog)
{
    for (; dialog && dialog->dialog_step != pnj->dialog_step; \
    dialog = dialog->next);
    if (dialog->dialog_step != pnj->dialog_step ||
    dialog->dialog_statue != GET_QUEST)
        return;
    if (dialog->next == NULL) {
        pnj->draw_text = 0;
        scene->game->quest->state = TAKEN;
        pnj->dialog_step = 3;
        return;
    }
    rpg_dialog_set_text(pnj, scene, dialog);
}