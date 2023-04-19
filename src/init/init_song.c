/*
** EPITECH PROJECT, 2023
** init_song
** File description:
** init_song
*/

#include "rpg.h"

void init_song(rpg_t *rpg)
{
    music_t *music = malloc(sizeof(music_t));

    rpg->music = NULL;
    if (!music)
        return;
    music->attenuation = 0;
    music->name = my_strdup("main_theme");
    music->music = sfMusic_createFromFile("assets/songs/main_theme.ogg");
    music->play = false;
    sfMusic_setLoop(music->music, sfTrue);
    sfMusic_setVolume(music->music, 25);
    sfMusic_setPitch(music->music, 0.9);
    rpg->music = music;
}
