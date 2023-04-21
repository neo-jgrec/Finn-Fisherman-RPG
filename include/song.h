/*
** EPITECH PROJECT, 2023
** song
** File description:
** song
*/

#ifndef SONG_
    #define SONG_

    #include "rpg.h"

    // DEFINES

    #define MAIN_MUSIC "./assets/songs/main_theme.ogg"
    #define DEATH_SOUND "./assets/songs/death.ogg"
    #define SWORD_SOUND "./assets/songs/sword_hit.ogg"

typedef struct mus_struct {
    char *name;
    sfMusic *music;
    bool is_playing;
    float attenuation;
    TAILQ_ENTRY(mus_struct) next;
} mus_t;

typedef struct snd_struct {
    char *name;
    sfSoundBuffer *sound_buf;
    sfSound *sound;
    float attenuation;
    TAILQ_ENTRY(snd_struct) next;
} snd_t;

typedef struct music_s {
    TAILQ_HEAD(musics, mus_struct) musics;
    TAILQ_HEAD(sounds, snd_struct) sounds;
} music_t;

    // INIT

    void init_song(rpg_t *rpg);

    // PLAY

    void play_loop_song(char *song, rpg_t *rpg);
    void play_sound(char *sound, rpg_t *rpg);

    // PAUSE

    void pause_loop_song(char *song, rpg_t *rpg);

    // STOP

    void stop_loop_song(char *song, rpg_t *rpg);

#endif /* !SONG_ */
