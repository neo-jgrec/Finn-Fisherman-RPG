/*
** EPITECH PROJECT, 2023
** start_fishing_minigame
** File description:
** start_fishing_minigame
*/

#include "rpg.h"

void play_fishing_game(win_t *win, fishing_t *game)
{
    if (!game->state)
        return;
    sfRenderWindow_drawRectangleShape(win->win,
    game->fish_bar, NULL);
    sfRenderWindow_drawSprite(win->win, game->fish.sp, NULL);
    game->clock += win->deltaT;
    if (game->clock > 10){
        game->state = false;
        game->clock = 0;
    }
}
