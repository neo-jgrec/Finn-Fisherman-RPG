/*
** EPITECH PROJECT, 2023
** project-maker
** File description:
** main
*/

#include "rpg.h"

int main(int ac, UNUSED char **av)
{
    srand(time(NULL));
    if (ac != 1)
        return 0;
    return rpg();
}
