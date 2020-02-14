/*
** EPITECH PROJECT, 2019
** many flags
** File description:
** flags
*/
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"
#include <stdio.h>
#include <unistd.h>

void usg_int(va_list arg)
{
    unsigned int mod;
    unsigned int nb = va_arg(arg, int);

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            mod = (nb % 10);
            nb = (nb - mod) / 10;
            my_put_nbr(nb);
            my_putchar(48 + mod);
        }
        else
            my_putchar(48 + nb % 10);
    }
}

char *prepbin(int src)
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

void binaire(va_list arg)
{
    int src = va_arg(arg, int);
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
    bin = my_revstr(bin);
    for (int k = 0; bin[k] != '\0'; ++k) {
        my_putchar(bin[k]);
    }
    free(bin);
}

char *hexa_binary(va_list arg)
{
    int src = va_arg(arg, int);
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

void x_maj(va_list arg)
{
    char *bin = hexa_binary(arg);
    char *hex = prep_hex(bin);
    int tab[4] = {1, 2, 4, 8};
    int i = 0;
    int k = 0;

    hex[(my_strlen(bin) / 4) + 1] = '\0';
    for (int p = 0; bin[p] != '\0';) {
        i = 0;
        for (int h = 0; h < 4 && bin[p] != '\0'; ++h) {
            i = i + (bin[p] - 48) * tab[h];
            ++p;
        }
        i = convert(i);
        hex[k] = i;
        ++k;
    }
    my_revstr(hex);
    my_putstr(hex);
}