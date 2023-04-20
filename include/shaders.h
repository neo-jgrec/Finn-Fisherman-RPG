/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** shaders
*/

#ifndef SHADERS_H_
    #define SHADERS_H_

    #include "rpg.h"

typedef struct shaders_data_s
{
    sfShader *shader;
    sfRenderStates *states;
    void (*shader_func)(struct shaders_data_s *shader_data, rpg_t *rpg);
} shaders_data_t;

typedef struct all_shaders_s
{
    shaders_data_t *rain;
    shaders_data_t *snow;
} all_shaders_t;

void init_shaders(rpg_t *rpg);

#endif /* !SHADERS_H_ */
