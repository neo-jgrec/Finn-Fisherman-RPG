/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** manage_skeleton
*/

#include "rpg.h"

static void set_position_eye(win_t *win,
    entity_t *player, rpg_t *rpg)
{
    int speed = 50;
    VEC dir = {player->pos.x - rpg->player->pos.x,
        player->pos.y - rpg->player->pos.y};
    float length = sqrt(dir.x * dir.x + dir.y * dir.y);

    if (player->state == ATTACK)
        speed = 300;
    dir.x = dir.x / length;
    if (SIGN(dir.x) != -SIGN(player->dir))
        dir.x = -dir.x;
    dir.y = dir.y / length;
    if (player->state == HIT)
        return;
    move_player(player, (VEC){0, win->deltaT * dir.y * -speed});
    check_collision(player, rpg->puzzle, 0);
    move_player(player, (VEC){win->deltaT * dir.x *
            -speed, 0});
    check_collision(player, rpg->puzzle, 1);
}

static void monster_dir(entity_t *monster, rpg_t *rpg)
{
    float dist = monster->pos.x - rpg->player->pos.x;

    monster->hor = 0;

    monster->hor = (dist < 0) ? 1 : -1;
    if (monster->state != HIT &&
        dist < 160 && dist > -160 && monster->roll.cd > 0.3)
        monster->state = ATTACK;
}

void set_var_eye(entity_t *monster, rpg_t *rpg)
{
    monster->health.damage_cd += rpg->win->deltaT;
    monster->roll.cd += rpg->win->deltaT;
    monster->time += rpg->win->deltaT;
    monster->grounded = on_ground(monster, rpg->puzzle);
    if (monster->state != ATTACK)
        monster_dir(monster, rpg);
    set_position_eye(rpg->win, monster, rpg);
}
