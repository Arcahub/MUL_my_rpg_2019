/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_pnj_from_conf.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include "my_json.h"
#include "components/get_from_config.h"
#include "my.h"
#include <stdlib.h>

static const char *path = "templates/pnjbutton.png";

static dialog_t *create_dialog_from_conf(json_object_t *js, dialog_t *next, game_t *game)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));

    if (dialog == NULL)
        return (NULL);
    dialog->next = next;
    if (!get_int_from_conf(js, (int *) &dialog->dialog_statue, "type") ||
    !get_int_from_conf(js, &dialog->speaker, "speaker"))
        return (NULL);
    dialog->text = my_strdup(get_str_from_conf(js, "message"));
    return (dialog);
}

static dialog_t *rpg_pnj_init_dialog(pnj_t *pnj, json_object_t *js, game_t *game)
{
    json_value_t *value = NULL;
    json_array_t *array = NULL;
    dialog_t *list = NULL;
    dialog_t *tmp = NULL;

    value = json_get_element_by_key(js, "dialog");
    if (!value || value->value_type != ARRAY)
        return (NULL);
    array = value->value;
    for (int i = 0; array->array[i]; i++) {
        if (array->array[i]->value_type != OBJECT)
            continue;
        value = json_get_element_by_key(array->array[i]->value, "type");
        if (value && value->value_type == INT) {
            tmp = create_dialog_from_conf(array->array[i]->value, list, game);
            list = (tmp) ? tmp : list;
        }
    }
    return (list);
}

static pnj_t *rpg_pnj_init_button(pnj_t *pnj)
{
    sfVector2f pos = {1500, 800};

    if (pnj->pnj_type == SHOP)
        return (pnj);
    pnj->button = create_game_object(NULL, path, pos, BUTTON);
    if (pnj->button == NULL)
        return (NULL);
    pnj->button->box.height = 150;
    pnj->button->box.width = 200;
    pnj->button->box.top = pos.x;
    pnj->button->box.left = pos.y;
}

pnj_t *rpg_pnj_init_extend_from_conf(game_object_t *object,
json_object_t *js, game_t *game, scene_t *scene)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    json_object_t *pnj_js = NULL;

    if (pnj == NULL)
        return(NULL);
    pnj->dialog_text = NULL;
    pnj->dialog_step = 0;
    pnj->draw_text = 0;
    pnj->json_path = my_strdup(get_str_from_conf(js, "json_path"));
    pnj_js = json_create_from_file(pnj->json_path);
    pnj->name = my_strdup(get_str_from_conf(pnj_js, "name"));
    if ((!get_int_from_conf(pnj_js, (int *) &pnj->pnj_id, "id") || \
    !get_int_from_conf(pnj_js, (int *) &pnj->pnj_type, "type")) && \
    (pnj->pnj_type == QUEST_PNJ && !get_int_from_conf(pnj_js, (int *) \
    &pnj->quest_id, "quest")) && (pnj->pnj_type != SHOP && (pnj->dialog = \
    rpg_pnj_init_dialog(pnj, pnj_js, game)) == NULL))
        return (NULL);
    pnj = rpg_pnj_init_button(pnj);
    return (pnj);
}