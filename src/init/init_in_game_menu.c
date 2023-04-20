/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_in_game_menu
*/

#include "rpg.h"

void init_in_game_menu(rpg_t *rpg)
{ 
    rpg->menu->in_game_menu = malloc(sizeof(in_game_menu_t));
    rpg->menu->in_game_menu->bg = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->menu->in_game_menu->bg,
        (sfVector2f){1600 / 1.5, 900 / 1.5});
    sfRectangleShape_setPosition(rpg->menu->in_game_menu->bg,
        (sfVector2f){1600 / 2, 900 / 2});
    sfRectangleShape_setFillColor(rpg->menu->in_game_menu->bg, (sfColor){0, 0,
        0, 200});
    rpg->menu->in_game_menu->panel_type = NONE_PANEL;
    rpg->menu->in_game_menu->text = sfText_create();
}
