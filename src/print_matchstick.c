/*
** EPITECH PROJECT, 2020
** print map
** File description:
** print map
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"

void print_board(int line, int nb_matches, data_t *info)
{
    for (int i = 0; info->board[i] != NULL; ++i)
        my_printf("%s\n", info->board[i]);
}