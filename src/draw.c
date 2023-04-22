/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw
*/

#include "rpg.h"

void button_manager(win_t *win, rpg_t *rpg, struct buttons *button_list);
void settings_menu(win_t *win, rpg_t *rpg);
void saves_menu_in_game(win_t *win, rpg_t *rpg);
void draw_inventory(rpg_t *rpg);

static void shader_switch(rpg_t *rpg, int intensity)
{
    switch (rpg->weather) {
        case RAIN:
            rpg->shaders->rain->shader_func(rpg->shaders->rain, rpg,
            intensity, rpg->shaders->water_drop);
            sfRenderWindow_drawRectangleShape(rpg->win->win,
            rpg->shader_layer, rpg->shaders->rain->states);
            break;
        case SNOW:
            rpg->shaders->rain->shader_func(rpg->shaders->rain, rpg,
            intensity, rpg->shaders->snow);
            sfRenderWindow_drawRectangleShape(rpg->win->win, rpg->shader_layer,
            rpg->shaders->rain->states);
            break;
        default:
            break;
    }
}

static void in_game_menu(win_t *win, rpg_t *rpg)
{
    if (rpg->menu->in_game_menu->panel_type != NONE_PANEL) {
        sfRenderWindow_drawRectangleShape(win->win,
        rpg->menu->in_game_menu->bg, NULL);
        button_manager(win, rpg, (struct buttons *)&(rpg->menu->in_game_menu
            ->nav_buttons));
        switch (rpg->menu->in_game_menu->panel_type) {
            case SETTINGS_PANEL: settings_menu(win, rpg);       break;
            case SAVE_PANEL: saves_menu_in_game(win, rpg);      break;
            case INVENTORY_PANEL: draw_inventory(rpg);          break;
            default:                                            break;
        }
    }
}

static void draw_some_elms(win_t *win, rpg_t *rpg)
{
    draw_parall(win, rpg->parall);
    draw_map(win, rpg->puzzle, rpg->puzzle->background);
    draw_npc_lst(win, rpg->npc);
    draw_map(win, rpg->puzzle, rpg->puzzle->death);
    draw_monsters(rpg);
    set_sprite(rpg->player, rpg);
    sfRenderWindow_drawSprite(win->win, rpg->player->sp, NULL);
    draw_text(rpg);
}

void draw(win_t *win, rpg_t *rpg)
{
    sfRenderWindow_clear(win->win, sfBlack);
    draw_some_elms(win, rpg);
    draw_map(win, rpg->puzzle, rpg->puzzle->map);
    draw_map(win, rpg->puzzle, rpg->puzzle->map);
    draw_map(win, rpg->puzzle, rpg->puzzle->foreground);
    draw_player_hud(rpg->player, rpg);
    draw_items(rpg);
    play_fishing_game(win, rpg->fishing, rpg->player, rpg);
    draw_infos_text(rpg);
    shader_switch(rpg, 100);
    if (rpg->menu->in_game_menu->panel_type != NONE_PANEL)
        in_game_menu(win, rpg);
    sfRenderWindow_display(win->win);
}
