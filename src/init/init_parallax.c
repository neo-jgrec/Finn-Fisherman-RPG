/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_parallax
*/

#include "rpg.h"
#include "parallax.h"

void init_parallax(rpg_t *rpg)
{
    rpg->font = malloc(sizeof(parallax_t));

    rpg->font->back_txt = sfTexture_createFromFile("assets/parallax/desert/layer0.png", NULL);
    rpg->font->back_spt = sfSprite_create();

    sfSprite_setTexture(rpg->font->back_spt, rpg->font->back_txt, sfTrue);
    return;
}
