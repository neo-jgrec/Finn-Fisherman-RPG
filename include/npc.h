/*
** EPITECH PROJECT, 2023
** npc
** File description:
** npc
*/

#ifndef NPC_
    #define NPC_

    #define SP_MERCHANT merchant->sprite_info.sprite_npc
    #define SP_ALCHEMIST alchemist->sprite_info.sprite_npc
    #define SP_CHEF chef->sprite_info.sprite_npc
    #define SP_PRIEST priest->sprite_info.sprite_npc
    #define NPC_SP npc->sprite_info.sprite_npc.sp
    #define NPC_RECT npc->sprite_info.pos_anim
    #define SP_ALCHEMIST alchemist->sprite_info.sprite_npc
    #define SP_CHEF chef->sprite_info.sprite_npc
    #define SP_PRIEST priest->sprite_info.sprite_npc

    #include "rpg.h"

    typedef struct anim_s {
        float clock_anim;
        int max_sec_anim;
        int max_anim;
    } anim_t;

    typedef struct sprite_npc_s {
        sfIntRect pos_anim;
        sprite_t sprite_npc;
        sfVector2f pos_npc;
    } snpc_t;

    typedef struct npc_struct {
        char *name;
        float clock_anim_selec;
        snpc_t sprite_info;
        anim_t anim;
        bool draw;
        struct npc_struct *next;
        struct npc_struct *prev;
    } npc_lt;

    typedef struct npc_list {
        size_t size;
        npc_lt *head;
        npc_lt *tail;
    } npc_l;

    typedef struct npc_s {
        npc_l *alchemist;
        npc_l *merchant;
        npc_l *chef;
        npc_l *priest;
    } npc_t;

    void init_merchant(npc_l *lst_merchant, char *name, sfVector2f pos,
    rpg_t *rpg);
    void init_priest(npc_l *lst_priest, char *name, sfVector2f pos, rpg_t *rpg);
    void init_alchemist(npc_l *lst_alchemist, char *name, sfVector2f pos,
    rpg_t *rpg);
    void init_chef(npc_l *lst_chef, char *name, sfVector2f pos, rpg_t *rpg);
    void init_npc_sprites(npc_t *npc, rpg_t *rpg);
    void init_npc(rpg_t *rpg);

    void verify_state_npc(entity_t *player, npc_t *npc);
    void draw_npc_lst(win_t *win, npc_t *npc);
    void manage_npc(rpg_t *rpg, npc_t *npc);
    void animate_npc(npc_t *npc, win_t *win);

#endif /* !NPC_ */
