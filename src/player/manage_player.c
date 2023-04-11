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

void manage_player(win_t *win, player_t *player, rpg_t *rpg)
{
    set_var(player, rpg);
    manage_jump(player, rpg);
    set_position(win, player, rpg);
    set_sprite(player, rpg);
}
