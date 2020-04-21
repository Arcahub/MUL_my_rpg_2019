/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_update.c
*/

#include "my_game.h"
#include "components/pnj/pnj.h"
#include "components/quest/quest.h"

void rpg_pnj_button_callback(pnj_t *pnj, scene_t *scene)
{
    dialog_t *tmp = pnj->dialog;

    for (; tmp && tmp->dialog_step != pnj->dialog_step; tmp = tmp->next);
    if (pnj->dialog_step != tmp->dialog_step)
        return;
    if (tmp->next == NULL && scene->game->quest->state == UNTAKEN) {
        scene->game->quest = rpg_quest_get_from_conf(QUEST_CONF[pnj->quest_id],
        scene->game);
        pnj->draw_text == 0;
    }
}

bool rpg_pnj_update(game_object_t *object, scene_t *scene)
{
    sfEvent event;
    pnj_t *pnj = (pnj_t *) object->extend;
    game_object_t *button = (game_object_t *) pnj->button;
    sfMouseButtonEvent mouse_button;
    sfVector2f pos = get_mouse_exact_pos(scene->game->window->window);
    int x = pos.x;
    int y = pos.y;

    while (sfRenderWindow_pollEvent(scene->window, &event)) {
        mouse_button = event.mouseButton;
        if (mouse_button.button != sfMouseLeft)
            return;
        if (button->callback != NULL && sfIntRect_contains(&button->box, x, y))
            rpg_pnj_button_callback(pnj, scene);
    }
    return (true);
}