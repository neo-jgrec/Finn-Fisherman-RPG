/*
** EPITECH PROJECT, 2023
** start_fishing_minigame
** File description:
** start_fishing_minigame
*/

#include "rpg.h"

static void calculate_display_position(fishing_t *game, entity_t *player)
{
    int speed = my_random(1, 3);
    float f_part = 0;

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
    game->speed_mov = speed;
    f_part = (float)my_random(1, 25);
    game->speed_mov += f_part / 100;
}

static void draw_sprites(win_t *win, fishing_t *game)
{
    sfRenderWindow_drawSprite(win->win, game->font.sp, NULL);
    sfRenderWindow_drawRectangleShape(win->win,
    game->fish_bar, NULL);
    sfRenderWindow_drawSprite(win->win, game->fish.sp, NULL);
}

void play_fishing_game(win_t *win, fishing_t *game, entity_t *player,
rpg_t *rpg)
{
    if (!game->state) {
        calculate_display_position(game, player);
        return;
    }
    printf("speed = %f\n", game->speed_mov);
    make_keep_zone_move(win, game);
    make_fish_move(rpg, game);
    change_zone_color(game);
    draw_sprites(win, game);
    end_game(game, win);
}
