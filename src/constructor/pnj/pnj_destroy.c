/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_pnj_from_conf.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include <stdlib.h>

static void free_string(char *string)
{
    if (string != NULL)
        free(string);
}

void free_dialog(dialog_t *dialog)
{
    dialog_t *tmp = NULL;

    if (dialog == NULL)
        return;
    for (; dialog; dialog = tmp) {
        tmp = dialog->next;
        free_string(dialog->text);
    }
}

void rpg_pnj_destroy(void *pt)
{
    pnj_t *pnj = NULL;
    if (pt == NULL)
        return;
    pnj = (pnj_t *) pt;
    free_text(pnj->dialog_text);
    free_dialog(pnj->dialog);
    free_string(pnj->json_path);
    free_string(pnj->name);
    free(pnj);
}