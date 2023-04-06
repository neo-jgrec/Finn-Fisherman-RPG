/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** utils
*/

#include "xml_parser.h"

void skip_whitespace(xml_parser_t *parser)
{
    while (parser->buffer_ptr < parser->buffer_end
    && IS_WHITESPACE(*parser->buffer_ptr))
        parser->buffer_ptr++;
}
