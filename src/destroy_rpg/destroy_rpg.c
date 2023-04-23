/*
** EPITECH PROJECT, 2023
** destroy_rpg
** File description:
** destroy_rpg
*/

#include "rpg.h"

void free_button(struct buttons *button_list);
void free_sprite_t(sprite_t sprite);
void free_loading(rpg_t *rpg);
void free_player(rpg_t *rpg);
void free_data(rpg_t *rpg);

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
    sfRectangleShape_destroy(rpg->menu->title);
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

void free_assets(rpg_t *rpg)
{
    asset_t *a = rpg->asset;
    sprite_t all_sprites[] = {
        a->pa.idle, a->pa.healing, a->pa.run, a->pa.death, a->pa.jump_1,
        a->pa.jump_2, a->pa.roll, a->pa.damage, a->pa.attack_1, a->pa.attack_2,
        a->pa.fishing, a->tileset, a->items, a->ma_eye.damage,
        a->ma_eye.attack_1, a->ma_eye.death, a->ma_eye.idle,
        a->ma_skeleton.attack_1, a->ma_skeleton.death, a->ma_skeleton.idle,
        a->ma_skeleton.shield, a->ma_skeleton.damage, a->ma_skeleton.run,
        a->ma_shroom.attack_1, a->ma_shroom.death, a->ma_shroom.idle,
        a->ma_shroom.damage, a->ma_shroom.run, a->ma_shroom.attack_2,
        rpg->player->health.potion_hud, rpg->player->health.health_hud,
        rpg->player->health.hud, rpg->player->health.xp_hud,
        rpg->player->health.button_f, rpg->parall->layers[0],
        rpg->parall->layers[1], rpg->parall->layers[2], rpg->parall->layers[3],
        rpg->parall->layers[4], rpg->parall->layers[5]
    };

    for (size_t i = 0; i < sizeof(all_sprites) / sizeof(sprite_t); i++)
        free_sprite_t(all_sprites[i]);
    free(rpg->asset);
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
    free_loading(rpg);
    free_assets(rpg);
    free_player(rpg);
    free_data(rpg);
}
