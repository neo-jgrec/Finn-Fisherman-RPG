/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_shaders
*/

#include "rpg.h"

void fall_shader_update(shaders_data_t *shader_data, rpg_t *rpg,
float drop_freq, sfTexture *texture)
{
    sfShader_setVec2Uniform(shader_data->shader, "u_resolution",
        (sfVector2f){rpg->win->size.x, rpg->win->size.y});
    sfShader_setFloatUniform(shader_data->shader, "u_time",
        DELTAT(rpg->win->warudo));
    sfShader_setFloatUniform(shader_data->shader, "n_drops",
        drop_freq);
    sfShader_setTextureUniform(rpg->shaders->rain->shader, "u_texture",
        texture);
    sfRectangleShape_setSize(rpg->shader_layer, (sfVector2f){rpg->win->size.x,
        rpg->win->size.y});
    sfShader_setFloatUniform(rpg->shaders->rain->shader, "u_velocity", 0.5);
    sfRectangleShape_setFillColor(rpg->shader_layer, sfWhite);
    sfRectangleShape_setPosition(rpg->shader_layer,
        (sfVector2f){(rpg->player->pos.x - rpg->win->size.x / 2),
        (rpg->player->pos.y - rpg->win->size.y / 2)});
}

void init_shaders(rpg_t *rpg)
{
    rpg->shaders = malloc(sizeof(all_shaders_t));
    rpg->shaders->rain = malloc(sizeof(shaders_data_t));
    rpg->shader_layer = sfRectangleShape_create();
    rpg->shaders->rain->shader = sfShader_createFromFile(NULL, NULL,
        "assets/shaders/rain.frag");
    rpg->shaders->rain->states = malloc(sizeof(sfRenderStates));
    rpg->shaders->rain->states->shader = rpg->shaders->rain->shader;
    rpg->shaders->rain->states->transform = sfTransform_Identity;
    rpg->shaders->rain->states->texture = NULL;
    rpg->shaders->rain->states->blendMode = sfBlendAlpha;
    rpg->shaders->rain->shader_func = &fall_shader_update;
    rpg->shaders->water_drop = sfTexture_createFromFile(
        "assets/shaders/water_drop.png", NULL);
    rpg->shaders->snow = sfTexture_createFromFile(
        "assets/shaders/snow.png", NULL);
}
