/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** my_malloc
*/

#include <stdlib.h>

char *my_malloc(int j)
{
    char *str = malloc(sizeof(char) * (j + 1));

    if (str == NULL) {
        exit(84);
    }
    for (int i = 0; i <= j; ++i)
        str[i] = '\0';
    return (str);
}
