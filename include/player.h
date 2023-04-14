/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** player
*/

#ifndef _PLAYER_H__
    #define _PLAYER_H__

    #include "rpg.h"

    typedef struct rpg_s rpg_t;

    void init_player(asset_t *asset, rpg_t *rpg);

    void manage_player(win_t *win, entity_t *player, rpg_t *rpg);
    void move_player(entity_t *player, sfVector2f dir);
    void manage_jump(entity_t *player, rpg_t *rpg);
    void manage_roll(entity_t *player, rpg_t *rpg);
    void manage_heal(entity_t *player, rpg_t *rpg);
    void manage_attack(entity_t *player, rpg_t *rpg);
    void heal_anim(rpg_t *rpg);
    void death_anim(rpg_t *rpg);
    void attack_anim(rpg_t *rpg);

    void set_animation(entity_t *player, sprite_t sprite, int loop,
        void (*action)(rpg_t *));
    void set_sprite(entity_t *player, rpg_t *rpg);
    void return_to_idle(rpg_t *rpg);

    void draw_player_hud(entity_t *player, rpg_t *rpg);

    void hit_player(rpg_t *rpg, int damage);

#endif /* !_PLAYER_H__ */
