/*
** EPITECH PROJECT, 2020
** ia moves
** File description:
** functions to make computer play
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"

int anti_bug(data_t *info)
{
    for (int i = 1; info->board[i + 1]; ++i)
        if (info->pipes[i - 1] > 1)
            return (1);
    return (0);
}

void rm_matches(data_t *info, int line, move_t *ia_mv)
{
    int remove = 0;
    int i = my_strlen(info->board[0]);

    for (; remove < 1 && i >= 0; --i) {
        if (info->board[line][i] == '|') {
            info->board[line][i] = ' ';
            remove += 1;
        }
    }
    ia_mv->matches = remove;
    info->pipes[line - 1] -= remove;
}

void rm_full_line(data_t *info, move_t *ia_mv)
{
    int i = 0;
    int line = 0;
    int nb_matches = 0;

    for (line = 1; info->board[line + 1] && info->pipes[line - 1] < 1; ++line);
    nb_matches = info->pipes[line - 1];
    ia_mv->matches = nb_matches;
    for (i = 0; info->board[line][i] != 0; ++i);
    for (; i > 0 && nb_matches > 0; --i) {
        nb_matches -= (info->board[line][i] == '|')?1:0;
        info->board[line][i] = (info->board[line][i] == '|')?' ':
        info->board[line][i];
    }
    ia_mv->line = line;
    info->pipes[line - 1] = 0;
}

void rm_line_part(data_t *info, move_t *ia_mv)
{
    int i = 0;
    int line = 0;
    int nb_matches = 0;

    for (line = 1; info->board[line + 1] && info->pipes[line - 1] <= 1; ++line);
    for (i = 0; info->board[line][i] != 0; ++i);
    for (; i >= 0 && nb_matches < 1; --i) {
        nb_matches += (info->board[line][i] == '|')?1:0;
        info->board[line][i] = (info->board[line][i] == '|')?' ':
        info->board[line][i];
    }
    info->pipes[line - 1] -= nb_matches;
    ia_mv->line = line;
    ia_mv->matches = nb_matches;
}

void rm_match(data_t *info, move_t *ia_mv)
{
    int remove = 0;
    int i = my_strlen(info->board[0]);
    int line = 0;

    for (line = 1; info->board[line + 1] && info->pipes[line - 1] < 1; ++line);
    for (; remove < 1 && i >= 0; --i) {
        if (info->board[line][i] == '|') {
            info->board[line][i] = ' ';
            remove += 1;
        }
    }
    ia_mv->line = line;
    ia_mv->matches = remove;
    info->pipes[line - 1] -= remove;
}