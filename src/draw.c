/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw
*/

#include "rpg.h"

static void shader_switch(rpg_t *rpg)
{
    switch (rpg->weather) {
        case RAIN:
            rpg->shaders->rain->shader_func(rpg->shaders->rain, rpg,
            100, rpg->shaders->water_drop);
            sfRenderWindow_drawRectangleShape(rpg->win->win,
            rpg->shader_layer, rpg->shaders->rain->states);
            break;
        case SNOW:
            rpg->shaders->rain->shader_func(rpg->shaders->rain, rpg,
            100, rpg->shaders->snow);
            sfRenderWindow_drawRectangleShape(rpg->win->win, rpg->shader_layer,
            rpg->shaders->rain->states);
            break;
        default:
            break;
    }
}

void draw(win_t *win, rpg_t *rpg)
{
    sfRenderWindow_clear(win->win, sfBlack);
    draw_parall(win, rpg->parall);
    draw_map(win, rpg->puzzle, rpg->puzzle->background);
    draw_npc_lst(win, rpg->npc);
    draw_map(win, rpg->puzzle, rpg->puzzle->death);
    draw_monsters(rpg);
    set_sprite(rpg->player, rpg);
    sfRenderWindow_drawSprite(win->win, rpg->player->sp, NULL);
    draw_text(rpg);
    draw_map(win, rpg->puzzle, rpg->puzzle->map);
    draw_map(win, rpg->puzzle, rpg->puzzle->map);
    draw_map(win, rpg->puzzle, rpg->puzzle->foreground);
    draw_player_hud(rpg->player, rpg);
    play_fishing_game(win, rpg->fishing, rpg->player, rpg);
    shader_switch(rpg);
    sfRenderWindow_display(win->win);
}
