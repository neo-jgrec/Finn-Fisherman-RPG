/*
** EPITECH PROJECT, 2023
** free_song
** File description:
** free_song
*/

#include "rpg.h"

void free_song(music_t *music)
{
    if (music) {
        sfMusic_stop(music->music);
        sfMusic_destroy(music->music);
        free(music->name);
        free(music);
    }
}
