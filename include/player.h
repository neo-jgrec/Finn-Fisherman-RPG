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
    void heal_anim(rpg_t *rpg, entity_t *entity);
    void death_anim(rpg_t *rpg, entity_t *entity);
    void attack_anim(rpg_t *rpg, entity_t *entity);

    void set_animation(entity_t *player, sprite_t sprite, int loop,
        void (*action)(rpg_t *, entity_t *entity));
    void set_sprite(entity_t *player, rpg_t *rpg);
    void flip(entity_t *player);
    void return_to_idle(rpg_t *rpg, entity_t *entity);

    void draw_player_hud(entity_t *player, rpg_t *rpg);
    void draw_button_hud(entity_t *player, rpg_t *rpg);

    void check_spikes_collision(rpg_t *rpg, entity_t *player, puzzle_t *puzzle);
    void check_monster_collision(rpg_t *rpg, entity_t *player);
    void check_fishing_spot(entity_t *player, puzzle_t *puzzle);
    void hit_player(rpg_t *rpg, int damage, entity_t *entity);
    void manage_fishing(entity_t *player, rpg_t *rpg);
    void check_sign(entity_t *player, puzzle_t *puzzle, rpg_t *rpg);
    void set_stat(rpg_t *rpg, entity_t *player);
    void check_items(rpg_t *rpg);

#endif /* !_PLAYER_H__ */
