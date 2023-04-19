/*
** EPITECH PROJECT, 2023
** song
** File description:
** song
*/

#ifndef SONG_
    #define SONG_

    #include "rpg.h"

    typedef struct music_s {
        char *name;
        bool play;
        float attenuation;
        sfMusic *music;
    } music_t;

    void init_song(rpg_t *rpg);
    void manage_song(rpg_t *rpg);

#endif /* !SONG_ */
