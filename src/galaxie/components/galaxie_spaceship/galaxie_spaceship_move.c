/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_spaceship_move
*/

#include "galaxie/galaxie_spaceship.h"
#include "player.h"
#define ABS(X) ((X<0)?(-X):(X))


// void galaxie_spaceship_move(game_object_t *object, scene_t *scene)
// {
//     sfView *view = (sfView *) sfRenderWindow_getView(scene->window);
//     sfVector2f pos = {0, 0};
// 
//     if (view == NULL)
//         return;
//     object->move.x *= 15;
//     object->move.y *= 15;
//     move_object(object);
//     pos.x = object->pos.x + object->box.width / 2;
//     pos.y = object->pos.y + object->box.height / 2;
//     sfView_setCenter(view, pos);
//     sfRenderWindow_setView(scene->window, view);
//     object->move = (sfVector2f) {0, 0};
// }

<<<<<<< HEAD
static void galaxie_spaceship_scale_move_vector(game_object_t *object)
{
    float tmp = 0;

    if (ABS(object->move.x) <= 10 && ABS(object->move.y) <= 10) {
        printf("salut\n");
        return;
    }
=======
static void galaxie_spaceship_compute_move_vector(game_object_t *object)
{
    float tmp = 0;

    if (ABS(object->move.x) <= 10 && ABS(object->move.x) <= 10)
        return;
>>>>>>> 61b0536d55921c47ca5a7f7ab19c31e4ae2cbc51
    if (ABS(object->move.x) > ABS(object->move.y)) {
        tmp = object->move.x;
        object->move.x = (object->move.x > 0) ? 10 : - 10;
        object->move.y = (object->move.x < 0) ?
        - 10 * object->move.y / tmp : 10 * object->move.y / tmp;
    } else if (ABS(object->move.y) > ABS(object->move.x)) {
        tmp = object->move.y;
        object->move.y = (object->move.y > 0) ? 10 : -10;
        object->move.x = (object->move.y < 0) ?
        - 10 * object->move.x / tmp : 10 * object->move.x / tmp;
    } else {
        object->move.y = (object->move.y > 0) ? 10 : -10;
        object->move.x = (object->move.x > 0) ? 10 : - 10;
    }
}

static void galaxie_spaceship_compute_move_vector(game_object_t *object)
{
    player_t *player = object->extend;
    sfVector2f center = object->pos;

    center.x += object->box.width / 2;
    center.y += object->box.height / 2;
    object->move.x = player->galaxie_dest.x - center.x;
    object->move.y = player->galaxie_dest.y - center.y;
<<<<<<< HEAD
    printf("previous ! %f : %f\n", object->move.x, object->move.y);
    galaxie_spaceship_scale_move_vector(object);
=======
    galaxie_spaceship_scale_vector(object);
>>>>>>> 61b0536d55921c47ca5a7f7ab19c31e4ae2cbc51
}

void galaxie_spaceship_move(game_object_t *object, scene_t *scene)
{
    sfView *view = (sfView *) sfRenderWindow_getView(scene->window);
    sfVector2f pos = {0, 0};

    if (view == NULL)
        return;
    galaxie_spaceship_compute_move_vector(object);
<<<<<<< HEAD
    printf("after ! %f : %f\n", object->move.x, object->move.y);
=======
    printf("%f : %f\n", object->move.x, object->move.y);
>>>>>>> 61b0536d55921c47ca5a7f7ab19c31e4ae2cbc51
    move_object(object);
    pos.x = object->pos.x + object->box.width / 2;
    pos.y = object->pos.y + object->box.height / 2;
    sfView_setCenter(view, pos);
    sfRenderWindow_setView(scene->window, view);
}