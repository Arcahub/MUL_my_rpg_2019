/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_text_from_conf.c
*/

#include "my_json.h"
#include "my_game.h"
#include "components/text_handler/text_handler.h"
#include "components/get_from_config.h"
#include "components/decor/decor_constructor.h"

static void set_color_from_conf(json_object_t *js, text_handler_t *text)
{
    json_value_t *value = json_get_element_by_key(js, "color");
    json_array_t *array = NULL;
    sfColor color;

    if (!value || value->value_type != ARRAY)
        return;
    array = value->value;
    if (!array || array->elem_count != 4)
        return;
    for (int i = 0; array->array[i]; i++)
        if (array->array[i]->value_type != INT)
            return;
    color.r = *((int *) (array->array[0]->value));
    color.g = *((int *) (array->array[1]->value));
    color.b = *((int *) (array->array[2]->value));
    color.a = *((int *) (array->array[3]->value));
    sfText_setColor(text->text, color);
}

static char *set_string_from_conf(json_object_t *js, text_handler_t *text)
{
    json_value_t *value = json_get_element_by_key(js, "string");
    json_value_t *font = json_get_element_by_key(js, "font");
    sfFont *font_style = NULL;

    if (font && font->value_type == STRING) {
        font_style = sfFont_createFromFile(font->value);
        if (font_style != NULL)
            sfText_setFont(text->text, font_style);
    }
    if (value && value->value_type == STRING) {
        sfText_setString(text->text, value->value);
        return (value->value);
    }
    return (NULL);
}

static void set_style_from_conf(json_value_t *text_style, text_handler_t *text)
{
    sfTextStyle style = sfTextRegular;

    if (*((int *) text_style->value) == 1)
        style = sfTextBold;
    if (*((int *) text_style->value) == 2)
        style = sfTextItalic;
    if (*((int *) text_style->value) == 3)
        style = sfTextUnderlined;
    if (*((int *) text_style->value) == 4)
        style = sfTextStrikeThrough;
    sfText_setStyle(text->text, style);
}

static text_handler_t *rpg_create_text_extend(game_object_t *object, json_object_t *js)
{
    text_handler_t *text = malloc(sizeof(text_handler_t));
    json_value_t *character_size = json_get_element_by_key(js, "size");
    json_value_t *text_style = json_get_element_by_key(js, "style");

    if (text == NULL)
        return (NULL);
    text->text = sfText_create();
    if (text->text == NULL || set_string_from_conf(js, text) == NULL) {
        free(text);
        return (NULL);
    }
    if (character_size && character_size->value_type == INT)
        sfText_setCharacterSize(text->text, *((int *) character_size->value));
    if (text_style && text_style->value_type == INT)
        set_style_from_conf(text_style, text);
    set_color_from_conf(js, text);
    return (text);
}

game_object_t *rpg_create_text_from_conf(game_object_t *last, json_object_t *js,
game_t *game, scene_t *scene)
{
    game_object_t *object = malloc(sizeof(game_object_t));
    text_handler_t *text = NULL;

    if (object == NULL)
        return (NULL);
    init_game_object(object);
    if (!get_vector2f_from_conf(js, &object->pos, "pos"))
        return (NULL);
    text = rpg_create_text_extend(object, js);
    object->texture = sfTexture_create(1, 1);
    if (text == NULL || object->texture == NULL) {
        free(object);
        return (NULL);
    }
    object->type = TEXT;
    object->extend = (void *) text;
    object->next = last;
    object->draw = &draw_text;
    return (object);
}