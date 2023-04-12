/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_player_hud
*/

#include "rpg.h"

static void draw_health_hud(player_t *player, rpg_t *rpg)
{
    sfIntRect health_rect = {0, 0,
        (int)(player->charge.health_hud.size.x *
        player->charge.health / rpg->data->max_health), 4};

    sfSprite_setTextureRect(player->charge.health_hud.sp, health_rect);
    sfSprite_setPosition(player->charge.health_hud.sp,
        (VEC){player->pos.x + 10, player->pos.y + 48});
    sfRenderWindow_drawSprite(rpg->win->win,
        player->charge.health_hud.sp, NULL);
}

static void draw_potion_hud(player_t *player, rpg_t *rpg)
{
    sfIntRect potion_rect = {0, 0, player->charge.potion * 4, 4};

    sfSprite_setTextureRect(player->charge.potion_hud.sp, potion_rect);
    sfSprite_setPosition(player->charge.potion_hud.sp,
        (VEC){player->pos.x + 10, player->pos.y + 60});
    sfRenderWindow_drawSprite(rpg->win->win,
        player->charge.potion_hud.sp, NULL);
}

static void draw_xp_hud(player_t *player, rpg_t *rpg)
{
    sfIntRect xp_rect = {0, 0,
        (int)(player->charge.xp_hud.size.x *
        rpg->data->xp / rpg->data->xp_to_lvl_up), 10};

    sfSprite_setTextureRect(player->charge.xp_hud.sp, xp_rect);
    sfSprite_setPosition(player->charge.xp_hud.sp,
        (VEC){player->pos.x, player->pos.y + 56});
    sfRenderWindow_drawSprite(rpg->win->win,
        player->charge.xp_hud.sp, NULL);
}

void draw_player_hud(player_t *player, rpg_t *rpg)
{
    if (player->charge.cd > 0.5)
        return;
    sfSprite_setPosition(player->charge.hud.sp,
        (VEC){player->pos.x, player->pos.y + 56});
    sfRenderWindow_drawSprite(rpg->win->win, player->charge.hud.sp, NULL);
    draw_health_hud(player, rpg);
    draw_potion_hud(player, rpg);
    draw_xp_hud(player, rpg);
}
