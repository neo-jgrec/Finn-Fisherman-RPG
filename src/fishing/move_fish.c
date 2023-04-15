/*
** EPITECH PROJECT, 2023
** move_fish
** File description:
** move_fish
*/

#include "rpg.h"

static void move_fish_up(win_t * win, fishing_t *game)
{
    game->fish->clock_fish += win->deltaT;

    if (game->fish->clock_fish > 0.002){
        game->fish->pos_fish.y -= game->fish->speed_fish;
        if (game->fish->pos_fish.y < game->font->pos_top.y)
            game->fish->pos_fish.y = game->font->pos_top.y;
        sfSprite_setPosition(game->fish->fish.sp, game->fish->pos_fish);
        game->fish->clock_fish = 0;
    }
}

static void move_fish_down(win_t * win, fishing_t *game)
{
    game->fish->clock_fish += win->deltaT;

    if (game->fish->clock_fish > 0.002){
        game->fish->pos_fish.y += game->fish->speed_fish;
        if (game->fish->pos_fish.y > game->font->pos_bot.y)
            game->fish->pos_fish.y = game->font->pos_bot.y;
        sfSprite_setPosition(game->fish->fish.sp, game->fish->pos_fish);
        game->fish->clock_fish = 0;
    }
}

void make_fish_move(rpg_t *rpg, fishing_t *game)
{
    if (rpg->input->fish_up.press)
        move_fish_up(rpg->win, game);
    if (rpg->input->fish_down.press)
        move_fish_down(rpg->win, game);
}
