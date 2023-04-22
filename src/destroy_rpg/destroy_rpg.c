/*
** EPITECH PROJECT, 2023
** destroy_rpg
** File description:
** destroy_rpg
*/

#include "rpg.h"

void free_button(struct buttons *button_list);

static void free_menus(rpg_t *rpg)
{
    free_button((struct buttons *)&rpg->menu->in_game_menu->nav_buttons);
    free_button((struct buttons *)&rpg->menu->in_game_menu->skill_buttons);
    free_button((struct buttons *)&rpg->menu->buttons);
    free_button((struct buttons *)&rpg->menu->res_buttons);
    free_button((struct buttons *)&rpg->menu->settings_buttons);
    for (size_t i = 0; rpg->menu->saves[i]; i++) {
        sfRectangleShape_destroy(rpg->menu->saves[i]->button->shape);
        free(rpg->menu->saves[i]->button);
        free(rpg->menu->saves[i]);
    }
    free(rpg->menu->saves);
    sfRectangleShape_destroy(rpg->menu->in_game_menu->bg);
    sfText_destroy(rpg->menu->in_game_menu->text);
    sfFont_destroy(rpg->menu->font);
    sfText_destroy(rpg->menu->text);
    sfRectangleShape_destroy(rpg->menu->bg);
    sfShader_destroy(rpg->menu->bg_shader);
    sfRectangleShape_destroy(rpg->menu->how_to_play);
    sfRectangleShape_destroy(rpg->menu->lore);
}

static void free_shaders(rpg_t *rpg)
{
    sfShader_destroy(rpg->shaders->rain->shader);
    free(rpg->shaders->rain->states);
    sfTexture_destroy(rpg->shaders->water_drop);
    sfTexture_destroy(rpg->shaders->snow);
    free(rpg->shaders->rain);
    free(rpg->shaders);
    free(rpg->menu->in_game_menu);
    free(rpg->menu->render_states);
    free(rpg->menu);
}

void destroy_rpg(rpg_t *rpg)
{
    if (!rpg)
        return;
    free_fishing(rpg);
    free_quest(rpg->quests);
    free_songs(rpg);
    free_window(rpg->win);
    free_menus(rpg);
    free_shaders(rpg);
}
