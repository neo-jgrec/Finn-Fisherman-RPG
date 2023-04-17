/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw
*/

#include "rpg.h"

void draw(win_t *win, rpg_t *rpg)
{
    sfRenderWindow_clear(win->win, sfBlack);
    sfRenderWindow_drawSprite(win->win, rpg->font->back_spt, NULL);
    draw_map(win, rpg->puzzle, rpg->puzzle->background);
    draw_map(win, rpg->puzzle, rpg->puzzle->map);
    set_sprite(rpg->player, rpg);
    sfRenderWindow_drawSprite(win->win, rpg->player->sp, NULL);
    draw_monsters(rpg);
    draw_map(win, rpg->puzzle, rpg->puzzle->foreground);
    draw_player_hud(rpg->player, rpg);
    play_fishing_game(win, rpg->fishing, rpg->player, rpg);
    sfRenderWindow_display(win->win);
}
