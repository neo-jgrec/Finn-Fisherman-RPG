/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** stop_loop_song
*/

#include "rpg.h"

void stop_loop_song(char *song, rpg_t *rpg)
{
    mus_t *musics;
    
    TAILQ_FOREACH(musics, (&rpg->music->musics), next) {
        if (my_strcmp(song, musics->name) == 0) {
            sfMusic_stop(musics->music);
            musics->is_playing = false;
        }
    }
    return;
}
