/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** death_anim
*/

#include "rpg.h"

void death_anim(rpg_t *rpg, entity_t *entity)
{
    int a = 0;

    entity->velocity = 0;
    if (entity->id == PLAYER) {
        stop_loop_song(MAIN_MUSIC, rpg);
        entity->state = IDLE;
        entity->health.health = rpg->data->tot_stat.max_health;
        entity->health.potion = rpg->data->tot_stat.max_potion;
        rpg->data->xp = 0;
        entity->pos = rpg->puzzle->spawn;
        rpg->player->health.cd = 0;
        while (DELTAT(rpg->win->time) < 3.5) {
            play_sound(DEATH_SOUND, rpg);
            youdead(rpg, rpg->loading, a);
            a += 4;
        }
    }
    return;
}
