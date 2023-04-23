/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_player
*/

#include "rpg.h"

static void set_var(entity_t *player, rpg_t *rpg)
{
    if (rpg->data->xp > rpg->data->xp_to_lvl_up) {
        rpg->data->xp -= rpg->data->xp_to_lvl_up;
        rpg->data->xp_to_lvl_up += 20;
        rpg->data->lvl += 1;
        add_info_text(rpg, sfGreen,
            (VEC){player->pos.x, player->pos.y - 50}, my_strdup("LVL UP"));
        rpg->data->lvl_point += 5;
    }
    player->time += rpg->win->deltaT;
    if (player->state != ATTACK && player->state != ROLL)
        player->hor = rpg->input->right.press - rpg->input->left.press;
    player->grounded = on_ground(player, rpg->puzzle);
    if (player->grounded) {
        player->jump.nb = rpg->data->tot_stat.jump;
        if (player->velocity > 0)
            player->velocity = 0;
    }
}

static void check_spot(entity_t *player, rpg_t *rpg)
{
    if (player->health.health > rpg->data->tot_stat.max_health)
        player->health.health = rpg->data->tot_stat.max_health;
    if (player->pos.y > 10000)
        hit_player(rpg, 10000, player);
    if (player->velocity > 1500)
        player->velocity = 1500;
    set_stat(rpg, player);
    check_items(rpg);
    check_sign(player, rpg->puzzle, rpg);
    check_fishing_spot(player, rpg->puzzle);
    check_spikes_collision(rpg, player, rpg->puzzle);
    check_monster_collision(rpg, player);
}

void manage_player(win_t *win, entity_t *player, rpg_t *rpg)
{
    check_spot(player, rpg);
    set_var(player, rpg);
    if (player->state == HIT)
        return;
    manage_fishing(player, rpg);
    manage_heal(player, rpg);
    manage_attack(player, rpg);
    if (player->state != HEALING && player->state != HIT &&
        player->state != ATTACK && player->state != FISHING) {
        manage_roll(player, rpg);
        if (player->state != ROLL)
            manage_jump(player, rpg);
    }
    if (player->state != HEALING)
        set_position(win, player, rpg);
}
