/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** return string
*/

void my_swap(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        ++i;
    }
    --i;
    while (i >= count) {
        my_swap(&str[count], &str[i]);
        ++count;
        --i;
    }
    return (str);
}
