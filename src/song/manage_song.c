/*
** EPITECH PROJECT, 2023
** manage_song
** File description:
** manage_song
*/

#include "rpg.h"

void manage_song(rpg_t *rpg)
{
    if (!rpg->music)
        return;
    if (!rpg->music->play) {
        rpg->music->play = true;
        sfMusic_play(rpg->music->music);
    }
}
