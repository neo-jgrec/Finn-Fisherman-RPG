/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** death_anim
*/

#include "rpg.h"

static void you_died_screen(rpg_t *rpg, entity_t *entity)
{
    sfVector2f pos = entity->pos;

    sfSprite_setPosition(rpg->loading->you_dead.sp, (pos));
    sfSprite_setPosition(rpg->player->sp, pos);
    for (int i = 0; i < 30; i++) {
        sfSprite_setColor(rpg->loading->you_dead.sp,
            sfColor_fromRGBA(255, 255, 255, 8.5 * 1));
        sfRenderWindow_drawSprite(rpg->win->win,
            rpg->loading->you_dead.sp, NULL);
        sfRenderWindow_drawSprite(rpg->win->win, entity->sp, NULL);
        sfRenderWindow_display(rpg->win->win);
        sfSleep(sfSeconds(0.05f));
    }
    sfRenderWindow_clear(rpg->win->win, sfBlack);
}

void death_anim(rpg_t *rpg, entity_t *entity)
{
    if (entity->id == PLAYER) {
        entity->state = IDLE;
        entity->health.health = rpg->data->max_health;
        you_died_screen(rpg, entity);
        entity->pos = rpg->puzzle->spawn;
    }
    return;
}
