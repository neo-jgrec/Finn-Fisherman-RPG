/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_shaders
*/

#include "rpg.h"

void rain_shader_update(shaders_data_t *shader_data, rpg_t *rpg)
{
    sfShader_setVec2Uniform(shader_data->shader, "u_resolution",
        (sfVector2f){WIN_X, WIN_Y});
    sfShader_setFloatUniform(shader_data->shader, "u_time",
        DELTAT(rpg->win->time));
    sfRectangleShape_setSize(rpg->shader_layer, (sfVector2f){WIN_X, WIN_Y});
    sfRectangleShape_setFillColor(rpg->shader_layer, sfWhite);
}

void init_shaders(rpg_t *rpg)
{
    rpg->shaders = malloc(sizeof(all_shaders_t));
    rpg->shaders->rain = malloc(sizeof(shaders_data_t));
    rpg->shader_layer = sfRectangleShape_create();
    rpg->shaders->rain->shader = sfShader_createFromFile(NULL, NULL,
        "assets/shaders/rain.frag");
    // set the shader u_texture uniform to the texture of the sprite
    sfShader_setTextureUniform(rpg->shaders->rain->shader, "u_texture",
        sfTexture_createFromFile("assets/loading/fish_0.jpg", NULL));
    sfShader_setFloatUniform(rpg->shaders->rain->shader, "u_velocity", 0.5);
    rpg->shaders->rain->states = malloc(sizeof(sfRenderStates));
    rpg->shaders->rain->states->shader = rpg->shaders->rain->shader;
    rpg->shaders->rain->states->transform = sfTransform_Identity;
    rpg->shaders->rain->states->texture = NULL;
    rpg->shaders->rain->states->blendMode = sfBlendAlpha;
    rpg->shaders->rain->shader_func = &rain_shader_update;
}
