/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** sokoban
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

int count_lines(char *buffer)
{
    int count_lines = 0;
    int i = 0;

    for (; buffer[i] != '\0'; ++i) {
        if (buffer[i] == '\n')
            ++count_lines;
        }
    return (count_lines);
}

int count_colums(char *buffer)
{
    int count_colums = 0;
    int i = 0;

    for (; buffer[i] != '\n'; ++i);
    ++i;
    for (; buffer[i] != '\n'; ++i) {
        ++count_colums;
        }
    return (count_colums);
}

char **tab_of_char(char *buffer, int size)
{
    int lines = count_lines(buffer);
    char **char_tab = malloc(sizeof(char *) * (lines + 1));
    int columns = count_colums(buffer);
    int j = 0;
    int i = 0;
    int p = 0;

    char_tab[lines] = NULL;
    for (; j < lines; ++j) {
        char_tab[j] = malloc(sizeof(char) * (columns + 10));
        for (p = 0; buffer[i] != '\n'; ++p, ++i) {
            char_tab[j][p] = buffer[i];
        }
        ++i;
    }
    return (char_tab);
}

int main(int ac, char **av)
{
    error(ac);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        descr();
        return (0);
    }
    struct stat st;
    stat(av[1], &st);
    int size = st.st_size;
    char *buffer = malloc(sizeof(char) * (size + 1));
    buffer = fs_open_file(av[1], buffer, size);
    error_handling(buffer);
    char **map_in_tab = tab_of_char(buffer, size);
    player_t *player = malloc(sizeof(player_t));
    player->x = 0;
    player->y = 0;
    place_t *place_o = malloc(sizeof(place_t) * count_o(buffer));
    get_pos_o(place_o, map_in_tab, buffer);
    if (display_ncurses(map_in_tab, buffer, player, place_o) == 1)
        return (1);
    return (0);
}
