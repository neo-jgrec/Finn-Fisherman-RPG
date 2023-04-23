/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_SKELETON
*/

#include "rpg.h"

void init_slash(rpg_t *rpg, entity_t *monster, monster_stat_t stat)
{
    monster->dir = 1;
    monster->id = SLASH;
    monster->state = IDLE;
    monster->prev_state = IDLE;
    monster->pos = stat.pos;
    monster->rect = (sfFloatRect){0, 0, 50, 300};
    monster->time = 0;
    set_animation(monster, rpg->asset->ma_ball.idle, 0, set_death);
    monster->jump = (jump_t){0, 0, 2, 2};
    monster->roll = (roll_t){0};
    monster->attack = (attack_t){0, 0};
    monster->health = (health_t){0};
    monster->damage = stat.damage;
    monster->loot = stat.loot;
    monster->health.health = stat.life;
    monster->velocity = 0;
    monster->drop_list = stat.drop_list;
}
