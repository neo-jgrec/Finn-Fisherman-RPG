/*
** EPITECH PROJECT, 2023
** project-maker
** File description:
** main
*/

#include "rpg.h"

int verifier2000(void);

int main(int ac, UNUSED char **av)
{
    srand(time(NULL));
    if (ac != 1)
        return 0;
    if (verifier2000() == 84)
        return 84;
    return rpg();
}
