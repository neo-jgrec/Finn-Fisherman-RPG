/*
** EPITECH PROJECT, 2023
** start_fishing_minigame
** File description:
** start_fishing_minigame
*/

#include "rpg.h"

static void calculate_display_position(fishing_t *game, entity_t *player)
{
    game->game_pos.x = player->pos.x + 700;
    game->game_pos.y = player->pos.y;
    sfSprite_setPosition(game->font.sp, game->game_pos);
    game->start_game_pos.x = game->game_pos.x;
    game->start_game_pos.y = game->game_pos.y + 330;
    game->end_game_pos.x = game->game_pos.x;
    game->end_game_pos.y = game->game_pos.y - 330;
    game->fish_pos = game->start_game_pos;
    game->fish_zone_pos = game->start_game_pos;
    sfRectangleShape_setPosition(game->fish_bar, game->fish_zone_pos);
    sfSprite_setPosition(game->fish.sp, game->fish_pos);
}

static void draw_sprites(win_t *win, fishing_t *game)
{
    sfRenderWindow_drawSprite(win->win, game->font.sp, NULL);
    sfRenderWindow_drawRectangleShape(win->win,
    game->fish_bar, NULL);
    sfRenderWindow_drawSprite(win->win, game->fish.sp, NULL);
}

static void end_game(fishing_t *game)
{
    if (game->fish_zone_pos.y <= game->end_game_pos.y) {
        game->state = false;
        game->clock_game = 0;
    }
}

void play_fishing_game(win_t *win, fishing_t *game, entity_t *player,
rpg_t *rpg)
{
    if (!game->state) {
        calculate_display_position(game, player);
        return;
    }
    make_fish_move(rpg, game);
    make_keep_zone_move(win, game);
    draw_sprites(win, game);
    end_game(game);
}
