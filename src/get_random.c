/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** get_random
*/

#include "rpg.h"

int my_random(int min, int max)
{
    return ((rand() + min) % (max - min + 1) + min);
}
