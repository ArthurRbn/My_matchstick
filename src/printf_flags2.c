/*
** EPITECH PROJECT, 2019
** printf flags 2
** File description:
** flags 2
*/
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"
#include <stdio.h>
#include <unistd.h>

void flag_big_s(va_list arg)
{
    char *src = va_arg(arg, char *);

    for (int i = 0; src[i] != '\0'; ++i) {
        if (32 <= src[i] && src[i] < 127) {
            my_putchar(src[i]);
        } else {
            my_putchar(92);
            print_ascii(src[i]);
        }
    }
}

void print_ascii(int c)
{
    int i = c;
    int oct = octals(i);
    if (oct <= 9) {
        my_putstr("00");
        my_put_nbr(oct);
    } else if (9 < oct && oct < 100) {
        my_putchar('0');
        my_put_nbr(oct);
    } else {
        my_put_nbr(oct);
    }
}

void octal(va_list arg)
{
    char *bin = hexa_binary(arg);
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
    my_putstr(oct);
}

void pointer(va_list arg)
{
    char *bin = pointer_binary(arg);
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
    my_putstr("0x");
    my_putstr(hex);
}

char *pointer_binary(va_list arg)
{
    long unsigned int src = va_arg(arg, long unsigned int);
    char *bin = pointer_bin(src);
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