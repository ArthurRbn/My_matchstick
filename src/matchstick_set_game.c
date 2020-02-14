/*
** EPITECH PROJECT, 2020
** matchstick set game
** File description:
** functions to init the game
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"

char **set_board(int len)
{
    int lines = len + 2;
    int col = len * 2 + 1;
    char **bd = malloc(sizeof(char *) * (lines + 1));
    int ns = 0;

    bd[lines] = NULL;
    for (int i = 0; i < lines; ++i) {
        bd[i] = malloc(sizeof(char) * (col + 1));
        bd[i][col] = 0;
    } for (int i = 0; i < col; ++i) {
        bd[0][i] = '*';
        bd[lines - 1][i] = '*';
    } for (int i = lines - 2; i > 0; --i) {
        bd[i][0] = '*';
        for (int j = 1; j < col; ++j) {
            bd[i][j] = (j - 1 < ns || j + 2 > col - ns)?' ':'|';
        } bd[i][col - 1] = '*';
        ++ns;
    }
    return (bd);
}

void set_matches_tab(data_t *info)
{
    int temp = 0;
    int i = 0;
    int match = 0;

    for (i = 0; info->board[i]; ++i);
    i -= 2;
    info->pipes = malloc(sizeof(int) * (i + 1));
    for (int i = 1; info->board[i + 1]; ++i) {
        match = 0;
        for (int j = 0; info->board[i][j] != 0; ++j) {
            match += (info->board[i][j] == '|')? 1 : 0;
        }
        info->pipes[i - 1] = match;
    }
}

data_t *start_game(char **av)
{
    data_t *info = malloc(sizeof(data_t));
    if (!info)
        return (0);
    info->line = my_getnbr(av[1]);
    info->matches = my_getnbr(av[2]);
    info->board = set_board(info->line);
    set_matches_tab(info);
    return (info);
}