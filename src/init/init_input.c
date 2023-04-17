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
    input->roll = init_key(sfKeyZ);
    input->left = init_key(sfKeyLeft);
    input->right = init_key(sfKeyRight);
    input->jump = init_key(sfKeySpace);
    input->heal = init_key(sfKeyR);
    input->interact = init_key(sfKeyF);
    input->attack = init_key(sfKeyE);
    input->fish_up = init_key(sfKeyUp);
    input->fish_down = init_key(sfKeyDown);
    input->fish_game = init_key(sfKeyP);
    rpg->input = input;
    loading_screen(rpg, rpg->loading, 100, 1);
}
