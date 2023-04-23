/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_skeleton
*/

#include "rpg.h"

static void set_position_shroom(win_t *win,
    entity_t *player, rpg_t *rpg)
{
    player->velocity += 2500 * win->deltaT;
    move_player(player, (VEC){0, 1 * win->deltaT * player->velocity});
    check_collision(player, rpg->puzzle, 0);
    if (((player->state == HIT || player->state == ATTACK) &&
        player->grounded))
        return;
    move_player(player, (VEC){player->hor * win->deltaT *
            250, 0});
    check_collision(player, rpg->puzzle, 1);

}

static void monster_dir(entity_t *monster, rpg_t *rpg)
{
    float dist = monster->pos.x - rpg->player->pos.x;

    monster->hor = 0;
    if (get_dist(monster->pos, rpg->player->pos) > 600)
        return;
    if (dist > 70)
        monster->hor = -1;
    if (dist < -70)
        monster->hor = 1;
    if (monster->state != ATTACK &&
        monster->state != HIT &&
        dist < 70 && dist > -70 && monster->roll.cd > 0.3)
        monster->state = ATTACK;
}

void set_var_ball(entity_t *monster, rpg_t *rpg)
{
    monster->health.damage_cd += rpg->win->deltaT;
    monster->roll.cd += rpg->win->deltaT;
    monster->time += rpg->win->deltaT;
    monster->grounded = on_ground(monster, rpg->puzzle);
    if (monster->state != ATTACK)
        monster_dir(monster, rpg);
    set_position_shroom(rpg->win, monster, rpg);
}
