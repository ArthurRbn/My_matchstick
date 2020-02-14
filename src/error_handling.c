/*
** EPITECH PROJECT, 2020
** error handlnig
** File description:
** functions to manage error handling
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"
#include "include/struct.h"

int check_max_match(char *str, int i, int match, int max)
{
    if (match > max) {
        write(1, "Error: you cannot remove more than ", 36);
        write(1, str, i);
        write(1, " matches per turn\n", 19);
        return (1);
    }
    return (0);
}

int check_synthax(char *str)
{
    for (int i = 0; str[i] != 0 && str[i] != 10; ++i)
        if (str[i] > 57 || str[i] < 48) {
            write(1, "Error: invalid input (positive number expected)\n", 50);
            return (1);
        }
    return (0);
}

int check_match_input(int match, int max_line, int max)
{
    char *str = nbr_str(max);
    int i = my_strlen(str);

    if (match == 0 || max_line == 0) {
        write(1, "Error: you have to remove at least one match\n", 46);
        if (max_line == 0)
            return (2);
        return (1);
    } else if (check_max_match(str, i, match, max) == 1)
        return (1);
    if (match < 0) {
        write(1, "Error: invalid input (positive number expected)\n", 50);
        return (1);
    }
    if (match > max_line && match <= max) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (1);
    }
    return (0);
}

int check_line_input(int line, int max, data_t *info)
{
    char *str = nbr_str(max);
    int i = my_strlen(str);

    if (line < 1 || line > max) {
        write(1, "Error: This line is out of range", 32);
        my_printf("\n");
        return (1);
    }
    return (0);
}