/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** o
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

int count_o(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] == 'O')
            ++count;
    }
    return (count);
}

void get_pos_x(place_t *place_x, char **map_in_tab, char *buffer)
{
    int k = 0;
    int lines = count_lines(buffer);
    int cols = 0;

    for (int i = 0; i < lines; ++i) {
        cols = my_strlen(map_in_tab[i]);
        for (int j = 0; j < cols - 1; ++j) {
            if (map_in_tab[i][j] == 'X') {
                place_x[k].x = j;
                place_x[k].y = i;
                ++k;
            }
        }
    }
}

void get_pos_o(place_t *place_o, char **map_in_tab, char *buffer)
{
    int k = 0;
    int lines = count_lines(buffer);
    int cols;

    for (int i = 0; i < lines - 1; ++i) {
        cols = my_strlen(map_in_tab[i]);
        for (int j = 0; j < cols - 1; ++j) {
            if (map_in_tab[i][j] == 'O') {
                place_o[k].x = j;
                place_o[k].y = i;
                ++k;
            }
        }
    }
}

void put_o(char *buffer, char **map_in_tab, place_t *place_o)
{
    for (int i = 0; i < count_o(buffer); ++i) {
        if (map_in_tab[place_o[i].y][place_o[i].x] == ' ') {
            map_in_tab[place_o[i].y][place_o[i].x] = 'O';
        }
    }
}
