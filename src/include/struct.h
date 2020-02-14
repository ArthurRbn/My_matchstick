/*
** EPITECH PROJECT, 2020
** structures file
** File description:
** structures
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct data_s
{
    char **board;
    int *pipes;
    int line;
    int matches;
} data_t;

typedef struct move_s
{
    int matches;
    int line;
} move_t;

#endif /* !STRUCT_H_ */
