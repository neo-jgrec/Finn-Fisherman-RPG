/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** free_songs
*/

#include "rpg.h"

static void close_all_tracks(rpg_t *rpg)
{
    mus_t *musics;
    snd_t *sounds;

    TAILQ_FOREACH(musics, (&rpg->music->musics), next)
        sfMusic_stop(musics->music);
    TAILQ_FOREACH(sounds, (&rpg->music->sounds), next)
        sfSound_stop(sounds->sound);
    return;
}

void free_songs(rpg_t *rpg)
{
    close_all_tracks(rpg);
    return;
}
