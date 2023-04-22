/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** checker
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#include "mars.h"

static const char *needed_files[] =
{
    "assets/fishing/f_bar.png",
    "assets/fishing/fish.png",
    "assets/Layers/farclouds.png",
    "assets/Layers/farmountains.png",
    "assets/Layers/mountains.png",
    "assets/Layers/nearclouds.png",
    "assets/Layers/sky.png",
    "assets/Layers/trees.png",
    "assets/loading/fish_0.jpg",
    "assets/loading/ugly_fish.png",
    "assets/map/map_1.xml",
    "assets/map/map_2.xml",
    "assets/menu/menu.frag",
    "assets/monsters/Eye/Attack.png",
    "assets/monsters/Eye/Death.png",
    "assets/monsters/Eye/Idle.png",
    "assets/monsters/Eye/Hit.png",
    "assets/monsters/Mushroom/Attack_1.png",
    "assets/monsters/Mushroom/Attack_2.png",
    "assets/monsters/Mushroom/Death.png",
    "assets/monsters/Mushroom/Idle.png",
    "assets/monsters/Mushroom/Hit.png",
    "assets/monsters/Mushroom/Projectile_sprite.png",
    "assets/monsters/Mushroom/Run.png",
    "assets/monsters/Skeleton/Attack.png",
    "assets/monsters/Skeleton/Death.png",
    "assets/monsters/Skeleton/Hit.png",
    "assets/monsters/Skeleton/Idle.png",
    "assets/monsters/Skeleton/Shield.png",
    "assets/monsters/Skeleton/Walk.png",
    "assets/npc/Alchemist.png",
    "assets/npc/Chef.png",
    "assets/npc/Merchant.png",
    "assets/npc/Priest.png",
    "assets/player/hud/button_E.png",
    "assets/player/hud/button_F.png",
    "assets/player/hud/health.png",
    "assets/player/hud/hud.png",
    "assets/player/hud/potion.png",
    "assets/player/hud/xp.png",
    "assets/player/attack_1.png",
    "assets/player/attack_2.png",
    "assets/player/death.png",
    "assets/player/fishing.png",
    "assets/player/healing.png",
    "assets/player/idle.png",
    "assets/player/jump_1.png",
    "assets/player/jump_2.png",
    "assets/player/roll.png",
    "assets/player/run.png",
    "assets/player/take_damage.png",
    "assets/quest/quest_font.ttf",
    "assets/quest/quest.xml",
    "assets/shaders/rain.frag",
    "assets/shaders/snow.png",
    "assets/shaders/water_drop.png",
    "assets/songs/death.ogg",
    "assets/songs/heal.ogg",
    "assets/songs/jump.ogg",
    "assets/songs/main_theme.ogg",
    "assets/songs/main_theme2.ogg",
    "assets/songs/menu.ogg",
    "assets/songs/sword_hit.ogg",
    "assets/tileset/items.png",
    "assets/tileset/tiles.png",
    "assets/AwasetePowder.ttf",
    "assets/Deutsch.ttf",
    "assets/how_to_play.png",
    "assets/icon.png",
    "assets/Inter-Medium.ttf",
    "assets/lore.png",
    "assets/title.png",
    "assets/youdied.png",
    "game_file/items.xml",
    "assets/monsters/troll/Attack.png",
    "assets/monsters/troll/Attack2.png",
    "assets/monsters/troll/Attack3.png",
    "assets/monsters/troll/Death.png",
    "assets/monsters/troll/Idle.png",
    "assets/monsters/troll/none_slash.png",
    "assets/monsters/troll/TakeHit.png",
    "assets/monsters/troll/troll_slash.png",
    "assets/monsters/troll/walk.png"
};

static const char *needed_folders[] =
{
    "assets/fishing",
    "assets/Layers",
    "assets/loading",
    "assets/map",
    "assets/menu",
    "assets/monsters/Eye",
    "assets/monsters/Mushroom",
    "assets/monsters/Skeleton",
    "assets/monsters/troll",
    "assets/npc",
    "assets/player/hud",
    "assets/player",
    "assets/quest",
    "assets/shaders",
    "assets/songs",
    "assets/tileset",
    "assets",
    "saves",
    "game_file"
};

static void check_file(char *file, int *result, char *filetype)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        my_printf("Error: %s \'%s\' not found\n", filetype, file);
        *result = 84;
    }
}

int verifier2000(void)
{
    int *result = malloc(sizeof(int));

    *result = 0;
    for (size_t i = 0; i < ARRAY_SIZE(needed_folders); i++)
        check_file((char*)needed_folders[i], result, "folder");
    if (*result == 84)
        return 84;
    for (size_t i = 0; i < ARRAY_SIZE(needed_files); i++)
        check_file((char*)needed_files[i], result, "file");
    return *result;
}
