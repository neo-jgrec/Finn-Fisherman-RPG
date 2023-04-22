/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_input
*/

#include "rpg.h"

static void switch_input(kv_t *input, sfKeyCode code, int press)
{
    if (code == input->code && input->press == press)
        input->press = 1 - input->press;
}

static void switch_key(win_t *win, input_t *input, int press)
{
    sfKeyCode code = win->event.key.code;

    switch_input(&input->roll, code, press);
    switch_input(&input->right, code, press);
    switch_input(&input->left, code, press);
    switch_input(&input->jump, code, press);
    switch_input(&input->heal, code, press);
    switch_input(&input->interact, code, press);
    switch_input(&input->attack, code, press);
    switch_input(&input->fish_up, code, press);
    switch_input(&input->fish_down, code, press);
    switch_input(&input->fish_game, code, press);
    switch_input(&input->quest, code, press);
}

void check_input(win_t *win, input_t *input)
{
    if (win->event.type == sfEvtKeyPressed)
        switch_key(win, input, 0);
    if (win->event.type == sfEvtKeyReleased)
        switch_key(win, input, 1);
}
