/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** play_sound
*/

#include "rpg.h"

void play_sound(char *sound, rpg_t *rpg)
{
    snd_t *sounds;

    TAILQ_FOREACH(sounds, (&rpg->music->sounds), next) {
        if (my_strcmp(sound, sounds->name) == 0 &&
        sfSound_getStatus(sounds->sound) != sfPlaying) {
            sfSound_setVolume(sounds->sound, rpg->sound_volume);
            sfSound_play(sounds->sound);
        }
    }
    return;
}
