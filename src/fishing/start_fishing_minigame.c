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
    printf("%f\n", game->clock);
    sfRenderWindow_drawRectangleShape(win->win,
    game->fish_bar, NULL);
    game->clock += win->deltaT;
    if (game->clock > 10){
        game->state = false;
        game->clock = 0;
    }
}
