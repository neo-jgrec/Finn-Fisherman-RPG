/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_input
*/

#include "rpg.h"

static kv_t init_key(sfKeyCode code)
{
    kv_t key = {0};

    key.code = code;
    key.press = 0;
    return key;
}

void init_input(rpg_t *rpg)
{
    input_t *input = malloc(sizeof(input_t));

    if (input == NULL)
        rpg->input = NULL;
    input->roll = init_key(sfKeyS);
    input->left = init_key(sfKeyQ);
    input->right = init_key(sfKeyD);
    input->jump = init_key(sfKeySpace);
    input->heal = init_key(sfKeyZ);
    input->interact = init_key(sfKeyE);
    input->attack = init_key(sfKeyR);
    rpg->input = input;
    loading_screen(rpg, rpg->loading, 100, 1);
}
