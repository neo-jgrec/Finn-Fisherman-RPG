/*
** EPITECH PROJECT, 2023
** destroy
** File description:
** destroy
*/

#ifndef DESTROY_
    #define DESTROY_

    #include "rpg.h"

    void destroy_rpg(rpg_t *rpg);
    void free_quest(quest_t *quest);
    void free_fishing(rpg_t *rpg);
    void free_window(win_t *win);
    void free_song(music_t *music);

#endif /* !DESTROY_ */
