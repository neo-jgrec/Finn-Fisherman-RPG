/*
** EPITECH PROJECT, 2023
** start_fishing_minigame
** File description:
** start_fishing_minigame
*/

#include "rpg.h"

static void set_game_pos(fishing_t *game, entity_t *player)
{
    game->font->pos_font.x = player->pos.x + 200;
    game->font->pos_font.y = player->pos.y - 150;
    game->font->pos_bot.x = game->font->pos_font.x;
    game->font->pos_bot.y = game->font->pos_font.y + 330;
    game->font->pos_top.x = game->font->pos_font.x;
    game->font->pos_top.y = game->font->pos_font.y - 330;
    game->fish->pos_fish = game->font->pos_font;
    game->zone->pos_zone = game->font->pos_font;
}

static void calculate_game_info(fishing_t *game, entity_t *player, win_t *win)
{
    int speed = my_random(1, 2);
    float f_part = 0;

    set_game_pos(game, player);
    sfSprite_setPosition(game->font->font.sp, game->font->pos_font);
    sfSprite_setPosition(game->fish->fish.sp, game->fish->pos_fish);
    sfRectangleShape_setPosition(game->zone->zone, game->zone->pos_zone);
    sfRectangleShape_setFillColor(game->zone->zone, sfGreen);
    game->fish->speed_fish = speed;
    game->info->game_time = my_random(10, 20);
    f_part = (float)my_random(1, 25);
    game->fish->speed_fish += f_part / 100;
    game->zone->speed_zone = game->fish->speed_fish + 0.2;
    game->fish->speed_fish *= win->deltaT;
    game->zone->speed_zone *= win->deltaT;
}

static void draw_sprites(win_t *win, fishing_t *game)
{
    sfRenderWindow_drawSprite(win->win, game->font->font.sp, NULL);
    sfRenderWindow_drawRectangleShape(win->win, game->zone->zone, NULL);
    sfRenderWindow_drawSprite(win->win, game->fish->fish.sp, NULL);
}

static void fishing_game(win_t *win, fishing_t *game, rpg_t *rpg)
{
    make_fish_move(win, game);
    make_keep_zone_move(rpg, game);
    change_zone_color(game);
    draw_sprites(win, game);
    end_game(game, win, rpg);
}

void play_fishing_game(win_t *win, fishing_t *game, entity_t *player,
    rpg_t *rpg)
{
    if (FISHING_GAME)
        return;
    if (player->health.fish_cd < 0 && player->state == FISHING)
        game->info->game_state = true;
    if (!game->info->game_state) {
        calculate_game_info(game, player, win);
        return;
    }
    if (game->info->game_start < 1){
        game->info->game_start += win->deltaT;
        if (rpg->player->state != FISHING)
            return end_game(game, rpg->win, rpg);
        draw_sprites(win, game);
        return;
    }
    fishing_game(win, game, rpg);
}
