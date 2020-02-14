/*
** EPITECH PROJECT, 2020
**  read_player_move_and_print_updated_board_game
** File description:
**  read_player_move_and_print_updated_board_game
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"

int check_input(char **av)
{
    int line = my_getnbr(av[1]);
    int match = my_getnbr(av[1]);

    for (int i = 0; av[1][i] != 0; ++i) {
        if (av[1][i] < 48 || av[1][i] > 58)
            return (84);
    }
    for (int i = 0; av[2][i] != 0; ++i) {
        if (av[2][i] < 48 || av[2][i] > 57)
            return (84);
    }
    if (line < 2 || line > 99) {
        return (84);
    } else if (match < 1) {
        return (84);
    }
    return (0);
}

int check_ai_win(data_t *info)
{
    for (int i = 0; i < info->line; ++i)
        if (info->pipes[i] != 0)
            return (0);
    my_printf("You lost, too bad...\n");
    return (2);
}

int check_player_win(data_t *info)
{
    for (int i = 0; i < info->line; ++i)
        if (info->pipes[i] != 0)
            return (0);
    my_printf("I lost... snif... but I'll get you next time!!\n");
    return (1);
}

int game_loop(data_t *info)
{
    int state = 0;
    int win = 0;

    print_board(0, 0, info);
    while (state == 0 && win == 0) {
        state = player_turn(info);
        if (state == 1) {
            my_putchar('\n');
            return (0);
        }
        win = check_ai_win(info);
        if (win != 0)
            return (win);
        ai_turn(info);
        win = check_player_win(info);
    }
    if (win != 0)
        return (win);
    return (0);
}

int main(int ac, char **av)
{
    data_t *info;
    int state = 0;

    if (ac != 3)
        return (84);
    if (check_input(av) == 84)
        return (84);
    info = start_game(av);
    if (!info)
        return (0);
    state = game_loop(info);
    return (state);
}