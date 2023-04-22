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

static void free_music(rpg_t *rpg)
{
    mus_t *entry;
    mus_t *tmp_entry;

    TAILQ_FOREACH_SAFE(entry, &rpg->music->musics, next, tmp_entry) {
        TAILQ_REMOVE(&rpg->music->musics, entry, next);
        free(entry->name);
        sfMusic_destroy(entry->music);
        free(entry);
    }
    return;
}

static void free_song(rpg_t *rpg)
{
    snd_t *entry;
    snd_t *tmp_entry;

    TAILQ_FOREACH_SAFE(entry, &rpg->music->sounds, next, tmp_entry) {
        TAILQ_REMOVE(&rpg->music->sounds, entry, next);
        free(entry->name);
        sfSound_destroy(entry->sound);
        sfSoundBuffer_destroy(entry->sound_buf);
        free(entry);
    }
    return;
}

void free_songs(rpg_t *rpg)
{
    close_all_tracks(rpg);
    free_music(rpg);
    free_song(rpg);
    free(rpg->music);
    return;
}
