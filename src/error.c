/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** error.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#include "../include/player.h"
#include "../include/my.h"

int count_x(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] == 'X')
            ++count;
    }
    return (count);
}

void error(int ac)
{
    if (ac != 2)
        exit(84);
}

int error_handling(char *buffer)
{
    int nb_o = count_o(buffer);
    int nb_x = count_x(buffer);

    for (int i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] != '\n' && buffer[i] != '#' && buffer[i] != 'P'
        && buffer[i] != 'X' && buffer[i] != 'O' && buffer[i] != ' ') {
            exit(84);
        }
    }
    if (nb_o != nb_x)
        exit(84);
}

int is_blocked(char **tab, place_t pos)
{
    return (((tab[pos.y - 1][pos.x] == '#' || tab[pos.y - 1][pos.x] == 'X')
        || (tab[pos.y + 1][pos.x] == '#' || tab[pos.y + 1][pos.x] == 'X'))
        && ((tab[pos.y][pos.x - 1] == '#' || tab[pos.y][pos.x - 1] == 'X')
        || (tab[pos.y][pos.x + 1] == '#' || tab[pos.y][pos.x + 1] == 'X')));
}

int x_check(char **map_in_tab, place_t *place_x, char *buffer)
{
    int count = 0;

    for (int i = 0; i < count_x(buffer); ++i) {
        count += is_blocked(map_in_tab, place_x[i]);
    }
    return (count);
}
