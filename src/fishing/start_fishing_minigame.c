/*
** EPITECH PROJECT, 2023
** start_fishing_minigame
** File description:
** start_fishing_minigame
*/

#include "rpg.h"

static void calculate_game_info(fishing_t *game, entity_t *player)
{
    int speed = my_random(1, 3);
    float f_part = 0;

    game->font->pos_font.x = player->pos.x + 700;
    game->font->pos_font.y = player->pos.y;
    game->font->pos_bot.x = game->font->pos_font.x;
    game->font->pos_bot.y = game->font->pos_font.y + 330;
    game->font->pos_top.x = game->font->pos_font.x;
    game->font->pos_top.y = game->font->pos_font.y - 330;
    game->fish->pos_fish = game->font->pos_font;
    game->zone->pos_zone = game->font->pos_font;
    sfSprite_setPosition(game->font->font.sp, game->font->pos_font);
    sfSprite_setPosition(game->fish->fish.sp, game->fish->pos_fish);
    sfRectangleShape_setPosition(game->zone->zone, game->zone->pos_zone);
    sfRectangleShape_setFillColor(game->zone->zone, sfGreen);
    game->zone->speed_zone = speed;
    f_part = (float)my_random(1, 25);
    game->zone->speed_zone += f_part / 100;
    game->fish->speed_fish = game->zone->speed_zone + 0.2;
}

static void draw_sprites(win_t *win, fishing_t *game)
{
    sfRenderWindow_drawSprite(win->win, game->font->font.sp, NULL);
    sfRenderWindow_drawRectangleShape(win->win, game->zone->zone, NULL);
    sfRenderWindow_drawSprite(win->win, game->fish->fish.sp, NULL);
}

void play_fishing_game(win_t *win, fishing_t *game, entity_t *player,
rpg_t *rpg)
{
    if (FISHING_GAME)
        return;
    if (rpg->input->fish_game.press && !game->info->game_state)
        game->info->game_state = true;
    if (!game->info->game_state) {
        calculate_game_info(game, player);
        return;
    }
    if (game->info->game_start < 1){
        game->info->game_start += win->deltaT;
        draw_sprites(win, game);
        return;
    }
    make_keep_zone_move(win, game);
    make_fish_move(rpg, game);
    change_zone_color(game);
    draw_sprites(win, game);
    end_game(game, win);
}
