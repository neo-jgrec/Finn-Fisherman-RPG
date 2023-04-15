/*
** EPITECH PROJECT, 2023
** start_fishing_minigame
** File description:
** start_fishing_minigame
*/

#include "rpg.h"

static void calculate_display_position(fishing_t *game, entity_t *player)
{
    game->pos_fish.x = player->pos.x + 700;
    game->pos_fish.y = player->pos.y;
    sfSprite_setPosition(game->font.sp, game->pos_fish);
    game->pos_fish.y += 330;
    sfRectangleShape_setPosition(game->fish_bar, game->pos_fish);
    sfSprite_setPosition(game->fish.sp, game->pos_fish);
}

void play_fishing_game(win_t *win, fishing_t *game, entity_t *player)
{
    if (!game->state) {
        calculate_display_position(game, player);
        return;
    }
    sfRenderWindow_drawSprite(win->win, game->font.sp, NULL);
    sfRenderWindow_drawRectangleShape(win->win,
    game->fish_bar, NULL);
    sfRenderWindow_drawSprite(win->win, game->fish.sp, NULL);
    game->clock += win->deltaT;
    if (game->clock > 10){
        game->state = false;
        game->clock = 0;
    }
}
