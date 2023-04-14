/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** is_rect_hover
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

bool is_rect_hover(sfVector2i mouse_pos, sfVector2f rect_pos,
sfVector2f rect_size)
{
    if (mouse_pos.x >= rect_pos.x && mouse_pos.x <= rect_pos.x + rect_size.x)
        if (mouse_pos.y >= rect_pos.y
            && mouse_pos.y <= rect_pos.y + rect_size.y)
            return true;
    return false;
}
