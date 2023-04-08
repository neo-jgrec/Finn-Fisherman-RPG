/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_input
*/

#include "rpg.h"

static void switch_key(win_t *win, input_t *input, int press)
{
    sfKeyCode code = win->event.key.code;

    if (code == input->bot.code && input->bot.press == press)
        input->bot.press = 1 - input->bot.press;
    if (code == input->top.code && input->top.press == press)
        input->top.press = 1 - input->top.press;
    if (code == input->left.code && input->left.press == press)
        input->left.press = 1 - input->left.press;
    if (code == input->right.code && input->right.press == press)
        input->right.press = 1 - input->right.press;
    if (code == input->space.code && input->space.press == press)
        input->space.press = 1 - input->space.press;
}

void check_input(win_t *win, input_t *input)
{
    if (win->event.type == sfEvtKeyPressed)
        switch_key(win, input, 0);
    if (win->event.type == sfEvtKeyReleased)
        switch_key(win, input, 1);
}
