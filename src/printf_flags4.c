/*
** EPITECH PROJECT, 2019
** pritnf flags
** File description:
** printf flags 4
*/

#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"
#include <stdio.h>
#include <unistd.h>

char *pointer_bin(long unsigned int src)
{
    int p = 2;
    char *bin;

    for (; 0 < src; ++p) {
        src = src / 2;
    }
    bin = malloc(sizeof(char) * (p));
    for (int k = 0; k != p; ++k) {
        bin[k] = '\0';
    }
    return (bin);
}

int octals(int src)
{
    char *bin = binaries(src);
    char *oct = prep_hex(bin);
    int tab[4] = {1, 2, 4};
    int i = 0;
    int k = 0;

    oct[(my_strlen(bin) / 3) + 1] = '\0';
    for (int p = 0; bin[p] != '\0';) {
        i = 0;
        for (int h = 0; h < 3 && bin[p] != '\0'; ++h) {
            i = i + (bin[p] - 48) * tab[h];
            ++p;
        }
        oct[k] = i + 48;
        ++k;
    }
    my_revstr(oct);
    i = my_getnbr(oct);
    return (i);
}

char *binaries(int src)
{
    char *bin = prepbin(src);
    int res = 0;

    if (src < 0) {
        src = src * -1;
        my_putchar('-');
    } else if (src == 0) {
        my_putchar('0');
        exit;
    }
    for (int i = 0; src >= 1; ++i) {
        res = src % 2;
        src = src / 2;

        bin[i] = res + 48;
    }
    return (bin);
}