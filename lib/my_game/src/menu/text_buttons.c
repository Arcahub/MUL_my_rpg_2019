/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** buttons
*/

#include "my_game.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static const sfIntRect *BUTTON_FRAME_KEYS[] = {
    &(sfIntRect){0, 0, 280, 163},
    &(sfIntRect){290, 0, 280, 163},
    &(sfIntRect){570, 0, 280, 163},
    NULL};

static const char *BUTTON_SOUND_PATH = \
"templates/sounds/ui_change_selection.ogg";

void update_button_rect(game_object_t *game_object, int id)
{
    int state = game_object->state;
    anim_t *anim = game_object->anim;

    sfSprite_setTextureRect(game_object->sprite, \
    *anim[state].frames_key[id]);
    game_object->box = *anim[state].frames_key[id];
    game_object->box.top = game_object->pos.y;
    game_object->box.left = game_object->pos.x;
}

bool update_text_button(game_object_t *button, scene_t *scene)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(scene->window);

    if (sfIntRect_contains(&button->box, pos.x, pos.y) && \
    button->state != SELECTED)
        update_button_rect(button, 0);
    else if (!sfIntRect_contains(&button->box, pos.x, pos.y) && \
    button->state != UNSELECTED)
        update_button_rect(button, 1);
    else
        update_game_object_frame(button);
    update_appearing_object(button, scene);
    return (true);
}

anim_t *create_text_button_anim(void)
{
    anim_t *anims = malloc(sizeof(anim_t) * 3);

    if (anims == NULL)
        return (NULL);
    anims[2].sound_buffer = NULL;
    anims[UNSELECTED].frames_key = (sfIntRect **)BUTTON_FRAME_KEYS;
    anims[UNSELECTED].loop = true;
    anims[UNSELECTED].frame_id = 0;
    anims[UNSELECTED].restart_id = 2;
    anims[UNSELECTED].sound_buffer = NULL;
    anims[UNSELECTED].sound_loop = false;
    anims[SELECTED].frames_key = (sfIntRect **)BUTTON_FRAME_KEYS;
    anims[SELECTED].loop = true;
    anims[SELECTED].frame_id = 0;
    anims[SELECTED].restart_id = 2;
    anims[SELECTED].sound_buffer = \
    sfSoundBuffer_createFromFile(BUTTON_SOUND_PATH);
    anims[SELECTED].sound_loop = false;
    return (anims);
}

game_object_t *create_text_button(game_object_t *last, char *path, \
sfVector2f pos)
{
    game_object_t *object = create_game_object(last, path, pos, TEXT_BUTTON);

    object->anim = create_text_button_anim();
    object->sound_effect = sfSound_create();
    object->update = &update_text_button;
    object->state = UNSELECTED;
    object->anim[object->state].frame_id = \
    object->anim[object->state].restart_id;
    init_appearing_object(object);
    init_game_object_frame(object);
    return (object);
}

