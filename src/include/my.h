/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H
#define _GNU_SOURCE

#include <stdarg.h>
#include <unistd.h>
#include "struct.h"

data_t *start_game(char **av);
char **set_board(int len);
void print_board(int line, int nb_matches, data_t *info);
void set_matches_tab(data_t *info);
int player_turn(data_t *info);
int my_printf(const char *format, ...);
void my_put_nbr(int nb);
int check_line_input(int line, int max, data_t *info);
int check_match_input(int match, int max_line, int max);
void ai_turn(data_t *info);
char *nbr_str(int nb);
int check_max_match(char *str, int i, int match, int max);
void ia_way(data_t *info, move_t *ia_mv);
int cut_lines(data_t *info, move_t *ia_mv);
void rm_matches(data_t *info, int line, move_t *ia_mv);
void remove_matches(int line, int matches, data_t *info);
void rm_full_line(data_t *info, move_t *ia_mv);
void rm_line_part(data_t *info, move_t *ia_mv);
void multiple_line(data_t *info, move_t *ia_mv);
void rm_match(data_t *info, move_t *ia_mv);
int get_line(data_t *info, int *line, char **temp);
int get_match(data_t *info, int *line, char **temp, int *match);
int anti_bug(data_t *info);
int check_synthax(char *str);

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
void my_put_nbr(int nb);
char *my_revstr(char *str);
int my_getnbr(char *src);
void binaire(va_list arg);
void usg_int(va_list arg);
char *prep_hex(char *src);
int convert(int i);
void x_maj(va_list arg);
int letter(int i);
void x_min(va_list arg);
char *hexa_binary(va_list arg);
void percent(va_list arg);
void flag_big_s(va_list arg);
void print_ascii(int c);
void octal(va_list arg);
void pointer(va_list arg);
char *pointer_binary(va_list arg);
char *pointer_bin(long unsigned int src);
char *prepbin(int src);
int octals(int src);
char *binaries(int src);
int my_printf(const char *format, ...);

#endif // MY_H
