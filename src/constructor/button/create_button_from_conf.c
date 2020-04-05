/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_button_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "components/button/callback_button.h"
#include "components/get_from_config.h"

game_object_t *rpg_create_button_from_conf(game_object_t *last, json_object_t *js, game_t *game, scene_t *scene)
{
    char *path = get_path_from_conf(js);
    sfVector2f pos = {0, 0};
    json_value_t *value = NULL;
    game_object_t *object = NULL;
    int callback_id = -1;

    value = json_get_element_by_key(js, "callback_id");
    if (value && value->value_type == INT)
        callback_id = *((int *) value->value);
    if (callback_id < 0 || callback_id >= MAX_CALLBACK_ID_BUTTON || \
    path == NULL || !get_vector2f_from_conf(js, &pos, "pos"))
        return (NULL);
    object = create_text_button(last, path, pos);
    object->callback = BUTTON_CALLBACK_PT[callback_id];
    return (object);
}