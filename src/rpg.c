/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** rpg
*/

#include "rpg.h"

int rpg(void)
{
    int ret = 0;
    rpg_t *rpg = init_rpg();

    rpg->win = init_win();
    ret = main_loop(rpg->win, rpg);
    return ret;
}