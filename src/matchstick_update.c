/*
** EPITECH PROJECT, 2020
** upadte matchstick
** File description:
** functions to update game
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"

void ai_turn(data_t *info)
{
    int line = 0;
    int nb_matches = 0;
    char *temp;
    move_t *ia_mv = malloc(sizeof(move_t));

    ia_mv->matches = 0;
    ia_mv->line = 0;
    my_printf("\nAI's turn...\n");
    ia_way(info, ia_mv);
    my_printf("AI removed %d match(es) from line %d\n",
    ia_mv->matches, ia_mv->line);
    print_board(ia_mv->line, ia_mv->matches, info);
    free(ia_mv);
}

void remove_matches(int line, int nb_matches, data_t *info)
{
    int i = 0;

    info->pipes[line - 1] -= nb_matches;
    for (i = 0; info->board[line][i] != 0; ++i);
    for (; i > 0 && nb_matches > 0; --i) {
        nb_matches -= (info->board[line][i] == '|')?1:0;
        info->board[line][i] = (info->board[line][i] == '|')?' ':
        info->board[line][i];
    }
}

int get_line(data_t *info, int *line, char **temp)
{
    int a = 0;
    size_t retour = 0;

    for (int state = 1; state == 1;) {
        write(1, "Line: ", 6);
        a = getline(temp, &retour, stdin);
        if (a == -1)
            return (1);
        if (check_synthax(*temp) == 0) {
            *line = my_getnbr(*temp);
            state = check_line_input(*line, info->line, info);
        }
    }
    return (0);
}

int get_match(data_t *info, int *line, char **temp, int *match)
{
    int a = 0;
    size_t retour = 0;

    for (int state = 1; state == 1;) {
        write(1, "Matches: ", 9);
        a = getline(temp, &retour, stdin);
        if (a == -1)
            return (1);
        if (check_synthax(*temp) == 0) {
            *match = my_getnbr(*temp);
            state = check_match_input(my_getnbr(*temp), info->pipes[*line - 1],
            info->matches);
            if (state == 2)
                return (2);
        }
    }
    return (0);
}

int player_turn(data_t *info)
{
    int line = 0;
    char *temp = NULL;
    int state = 2;
    int match = 0;

    my_printf("\nYour turn:\n");
    while (state == 2) {
        state = get_line(info, &line, &temp);
        if (state == 1)
            return (1);
        state = get_match(info, &line, &temp, &match);
        if (state == 1)
            return (1);
    }
    my_printf("Player removed %d match(es) from line %d\n", match, line);
    remove_matches(line, match, info);
    print_board(line, match, info);
    return (0);
}