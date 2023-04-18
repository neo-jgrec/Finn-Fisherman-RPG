/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** dist
*/

#include "rpg.h"

float get_dist(VEC pos_1, VEC pos_2)
{
    return sqrt(pow(pos_1.x - pos_2.x, 2) + pow(pos_1.y - pos_2.y, 2));
}
