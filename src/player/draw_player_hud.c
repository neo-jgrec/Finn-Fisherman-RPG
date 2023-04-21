/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_player_hud
*/

#include "rpg.h"

static void draw_lvl_hud(entity_t *player, rpg_t *rpg)
{
    char str[3] = {0};

    str[0] = rpg->data->lvl / 10 + 48;
    str[1] = rpg->data->lvl % 10 + 48;
    sfText_setString(player->health.lvl_hud, str);
    sfText_setPosition(player->health.lvl_hud,
        (VEC){player->pos.x - 55, player->pos.y + 46});
    sfRenderWindow_drawText(rpg->win->win,
        player->health.lvl_hud, NULL);
}

static void draw_health_hud(entity_t *player, rpg_t *rpg)
{
    sfIntRect health_rect = {0, 0,
        (int)(player->health.health_hud.size.x *
        player->health.health / rpg->data->player_stat.max_health), 4};

    sfSprite_setTextureRect(player->health.health_hud.sp, health_rect);
    sfSprite_setPosition(player->health.health_hud.sp,
        (VEC){player->pos.x + 10, player->pos.y + 48});
    sfRenderWindow_drawSprite(rpg->win->win,
        player->health.health_hud.sp, NULL);
}

static void draw_potion_hud(entity_t *player, rpg_t *rpg)
{
    sfIntRect potion_rect = {0, 0, player->health.potion * 4, 4};

    sfSprite_setTextureRect(player->health.potion_hud.sp, potion_rect);
    sfSprite_setPosition(player->health.potion_hud.sp,
        (VEC){player->pos.x + 10, player->pos.y + 60});
    sfRenderWindow_drawSprite(rpg->win->win,
        player->health.potion_hud.sp, NULL);
}

static void draw_xp_hud(entity_t *player, rpg_t *rpg)
{
    sfIntRect xp_rect = {0, 0,
        (int)(player->health.xp_hud.size.x *
        rpg->data->xp / rpg->data->xp_to_lvl_up), 10};

    sfSprite_setTextureRect(player->health.xp_hud.sp, xp_rect);
    sfSprite_setPosition(player->health.xp_hud.sp,
        (VEC){player->pos.x, player->pos.y + 56});
    sfRenderWindow_drawSprite(rpg->win->win,
        player->health.xp_hud.sp, NULL);
}

void draw_player_hud(entity_t *player, rpg_t *rpg)
{
    draw_button_hud(player, rpg);
    if (player->health.cd > 0.5)
        return;
    sfSprite_setPosition(player->health.hud.sp,
        (VEC){player->pos.x, player->pos.y + 56});
    sfRenderWindow_drawSprite(rpg->win->win, player->health.hud.sp, NULL);
    draw_health_hud(player, rpg);
    draw_potion_hud(player, rpg);
    draw_xp_hud(player, rpg);
    draw_lvl_hud(player, rpg);
}
