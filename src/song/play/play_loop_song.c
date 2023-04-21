/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** play_loop_song.c
*/

#include "rpg.h"

void play_loop_song(char *song, rpg_t *rpg)
{
    mus_t *musics;

    TAILQ_FOREACH(musics, (&rpg->music->musics), next) {
        if (my_strcmp(song, musics->name) == 0 && !musics->is_playing) {
            sfMusic_setVolume(musics->music, rpg->music_volume);
            sfMusic_play(musics->music);
            musics->is_playing = true;
            return;
        }
    }
}
