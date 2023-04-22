/*
** EPITECH PROJECT, 2023
** init_song
** File description:
** init_song
*/

#include "rpg.h"

static void init_loop_songs(music_t *music, char *fp)
{
    mus_t *new_music = malloc(sizeof(mus_t));

    if (music == NULL)
        return;
    new_music->name = my_strdup(fp);
    new_music->music = sfMusic_createFromFile(fp);
    sfMusic_setLoop(new_music->music, sfTrue);
    new_music->is_playing = false;
    new_music->attenuation = 0;
    TAILQ_INSERT_TAIL(&music->musics, new_music, next);
}

static void init_sounds(music_t *music, char *fp)
{
    snd_t *sound = malloc(sizeof(snd_t));

    if (sound == NULL)
        return;
    sound->name = my_strdup(fp);
    sound->sound_buf = sfSoundBuffer_createFromFile(fp);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->sound_buf);
    sound->attenuation = 0;
    TAILQ_INSERT_TAIL(&music->sounds, sound, next);
}

void init_song(rpg_t *rpg)
{
    rpg->music = malloc(sizeof(music_t));

    if (rpg->music == NULL)
        return;
    TAILQ_INIT(&rpg->music->musics);
    TAILQ_INIT(&rpg->music->sounds);
    init_loop_songs(rpg->music, MENU_MUSIC);
    init_loop_songs(rpg->music, MAIN_MUSIC);
    init_loop_songs(rpg->music, MAIN_MUSIC2);
    init_sounds(rpg->music, DEATH_SOUND);
    init_sounds(rpg->music, SWORD_SOUND);
    init_sounds(rpg->music, JUMP_SOUND);
    init_sounds(rpg->music, HEAL_SOUND);
    init_sounds(rpg->music, ROLL_SOUND);
}
