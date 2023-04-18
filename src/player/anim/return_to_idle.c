/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** return_to_idle
*/

#include "rpg.h"

void return_to_idle(rpg_t *rpg, entity_t *entity)
{
    entity->roll.cd = 0;
    entity->hor = rpg->input->right.press - rpg->input->left.press;
    entity->state = IDLE;
}
