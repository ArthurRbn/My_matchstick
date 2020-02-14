/*
** EPITECH PROJECT, 2020
** matchstick ia
** File description:
** functions to make computer play
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"

int cut_lines(data_t *info, move_t *ia_mv)
{
    for (int i = 1; info->board[i + 1]; ++i) {
        if (info->pipes[i - 1] > info->matches) {
            rm_matches(info, i, ia_mv);
            ia_mv->line = i;
            return (1);
        }
    }
    return (0);
}

int check_odd_number(data_t *info)
{
    int odd = 0;

    for (int i = 1; info->board[i + 1]; ++i) {
        if (info->pipes[i - 1] > 0)
            odd += 1;
    }
    return (odd % 2);
}

void multiple_line(data_t *info, move_t *ia_mv)
{
    if (check_odd_number(info) == 1) {
        rm_line_part(info, ia_mv);
        return;
    }
    if (check_odd_number(info) == 0)
        rm_full_line(info, ia_mv);
}

int one_line(data_t *info, move_t *ia_mv)
{
    int i = 1;

    for (i = 1; info->board[i + 1] != NULL && info->pipes[i - 1] < 1; ++i);
    if (info->pipes[i - 1] > 1) {
        rm_line_part(info, ia_mv);
        return (1);
    }
    if (info->pipes[i - 1] == 1) {
        rm_full_line(info, ia_mv);
        return (1);
    }
    return (0);
}

void ia_way(data_t *info, move_t *ia_mv)
{
    int full_lines = 0;

    if (cut_lines(info, ia_mv) == 1)
        return;
    for (int i = 1; info->board[i + 1] != NULL; ++i)
        if (info->pipes[i - 1] > 0)
            full_lines += 1;
    if (full_lines > 1 && anti_bug(info) == 1)
        multiple_line(info, ia_mv);
    else if (full_lines == 1)
        one_line(info, ia_mv);
    else
        rm_match(info, ia_mv);
}