/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** pause_loop_song
*/

#include "rpg.h"

void pause_loop_song(char *song, rpg_t *rpg)
{
    mus_t *musics;

    TAILQ_FOREACH(musics, (&rpg->music->musics), next) {
        if (my_strcmp(song, musics->name) == 0) {
            sfMusic_pause(musics->music);
            musics->is_playing = false;
        }
    }
    return;
}
