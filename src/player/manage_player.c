/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_player
*/

#include "rpg.h"

static void set_position(win_t *win, player_t *player, rpg_t *rpg)
{
    if (player->jump.jump < 0) {
        move_player(player, (VEC){0, 1 * win->deltaT * 800});
        check_collision(player, rpg->puzzle, 0);
    }
    move_player(player, (VEC){player->hor * win->deltaT * 450, 0});
    check_collision(player, rpg->puzzle, 1);
}

static void set_var(player_t *player, rpg_t *rpg)
{
    player->hor = rpg->input->right.press - rpg->input->left.press;
    player->grounded = on_ground(player, rpg->puzzle);
}

static void set_sprite(player_t *player, rpg_t *rpg)
{
    frame_t frame = player->frame;
    VEC scale = sfSprite_getScale(player->sp);
    int time = (int)(DELTAT(player->time) / frame.cd);

    if (player->hor == 1)
        sfSprite_setScale(player->sp, (VEC){fabs(scale.x), scale.y});
    if (player->hor == -1)
        sfSprite_setScale(player->sp, (VEC){-fabs(scale.x), scale.y});
    sfIntRect rect = (sfIntRect){time %
        frame.nb * frame.size, 0, frame.size, frame.size};
    if (frame.loop == 0 && time >= frame.nb)
        rect = (sfIntRect){(frame.nb - 1) *
            frame.size, 0, frame.size, frame.size};
    if (frame.loop == 0 && time > frame.nb && frame.action != NULL)
        frame.action(rpg);
    sfSprite_setPosition(player->sp, player->pos);
    sfSprite_setTextureRect(player->sp, rect);
}

void manage_player(win_t *win, player_t *player, rpg_t *rpg)
{
    set_var(player, rpg);
    manage_jump(player, rpg);
    set_position(win, player, rpg);
    set_sprite(player, rpg);
}
