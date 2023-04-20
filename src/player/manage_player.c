/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_player
*/

#include "rpg.h"

static void set_var(entity_t *player, rpg_t *rpg)
{
    player->time += rpg->win->deltaT;
    if (player->state != ATTACK && player->state != ROLL)
        player->hor = rpg->input->right.press - rpg->input->left.press;
    player->grounded = on_ground(player, rpg->puzzle);
    if (player->grounded) {
        player->jump.nb = rpg->data->jump;
        if (player->velocity > 0)
            player->velocity = 0;
    }
}

static void check_spot(entity_t *player, rpg_t *rpg)
{
    check_sign(player, rpg->puzzle, rpg);
    check_fishing_spot(player, rpg->puzzle);
    check_spikes_collision(rpg, player, rpg->puzzle);
    check_monster_collision(rpg, player);
}

void manage_player(win_t *win, entity_t *player, rpg_t *rpg)
{
    check_spot(player, rpg);
    set_var(player, rpg);
    manage_heal(player, rpg);
    manage_attack(player, rpg);
    if (manage_fishing(player, rpg))
        return;
    if (player->state != HEALING && player->state != HIT &&
        player->state != ATTACK) {
        if (rpg->data->roll == 1)
            manage_roll(player, rpg);
        if (player->state != ROLL)
            manage_jump(player, rpg);
    }
    if (player->state != HEALING)
        set_position(win, player, rpg);
}
