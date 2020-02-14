/*
** EPITECH PROJECT, 2019
** printf flags 3
** File description:
** flags n3
*/
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"
#include <stdio.h>
#include <unistd.h>

char *prep_hex(char *src)
{
    int lon = my_strlen(src);
    char *hex = malloc(sizeof(char) * (lon / 4 + 4));
    for (int i = 0; i < (lon / 4 + 4); ++i) {
        hex[i] = '\0';
    }
    return (hex);
}

int convert(int i)
{
    if (i < 10) {
        i = i + 48;
        return (i);
    } else if (9 < i) {
        i = i + 55;
        return (i);
    }
}

int letter(int i)
{
    if (i < 10) {
        i = i + 48;
        return (i);
    } else if (9 < i) {
        i = i + 87;
        return (i);
    }
}

void x_min(va_list arg)
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
        i = letter(i);
        hex[k] = i;
        ++k;
    }
    my_revstr(hex);
    my_putstr(hex);
}

void percent(va_list arg)
{
    my_putchar('%');
}