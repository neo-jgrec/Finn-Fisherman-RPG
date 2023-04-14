/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_player
*/

#include "rpg.h"

static void set_position(win_t *win, player_t *player, rpg_t *rpg)
{
    player->velocity += 2500 * win->deltaT;

    move_player(player, (VEC){0, 1 * win->deltaT * player->velocity});
    check_collision(player, rpg->puzzle, 0);
    if ((player->state == ATTACK && player->grounded))
        return;
    if (player->state != ROLL)
        move_player(player, (VEC){player->hor * win->deltaT *
            rpg->data->speed, 0});
    else
        move_player(player,
            (VEC){player->roll.save_dir * win->deltaT * 800, 0});
    check_collision(player, rpg->puzzle, 1);
}

static void set_var(player_t *player, rpg_t *rpg)
{
    player->time += rpg->win->deltaT;
    if (player->state != ATTACK)
        player->hor = rpg->input->right.press - rpg->input->left.press;
    player->grounded = on_ground(player, rpg->puzzle);
    if (player->grounded) {
        player->jump.nb = rpg->data->jump;
        if (player->velocity > 0)
            player->velocity = 0;
    }
}

void manage_player(win_t *win, player_t *player, rpg_t *rpg)
{
    if (rpg->input->interact.press)
        hit_player(rpg, 10);
    set_var(player, rpg);
    manage_heal(player, rpg);
    manage_attack(player, rpg);
    if (player->state != HEALING && player->state != HIT &&
        player->state != ATTACK) {
        if (rpg->data->roll == 1)
            manage_roll(player, rpg);
        if (player->state != ROLL)
            manage_jump(player, rpg);
    }
    if (player->state != HEALING)
        set_position(win, player, rpg);
    set_sprite(player, rpg);
}
