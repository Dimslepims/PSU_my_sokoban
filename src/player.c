/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** player
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

void player_place(char **char_tab, char *buffer, player_t *player)
{
    int lines = count_lines(buffer);
    int cols;

    for (int i = 0; i < lines; ++i) {
        cols = my_strlen(char_tab[i]);
        for (int j = 0; j < cols; ++j) {
            if (char_tab[i][j] == 'P') {
                player->y = i;
                player->x = j;
            }
        }
    }
}

void player_left(char **char_tab, char *buffer, player_t *player,
    place_t *place_o)
{
    if (char_tab[player->y][player->x - 1] == ' '
    || char_tab[player->y][player->x - 1] == 'O') {
        char_tab[player->y][player->x - 1] = 'P';
        char_tab[player->y][player->x] = ' ';
    } else if (char_tab[player->y][player->x - 1] == 'X'
    && (char_tab[player->y][player->x - 2] == ' '
    || char_tab[player->y][player->x - 2] == 'O')) {
        char_tab[player->y][player->x - 1] = 'P';
        char_tab[player->y][player->x] = ' ';
        char_tab[player->y][player->x - 2] = 'X';
    }
}

void player_right(char **char_tab, char *buffer, player_t *player,
    place_t *place_o)
{
    if (char_tab[player->y][player->x + 1] == ' '
    || char_tab[player->y][player->x + 1] == 'O') {
        char_tab[player->y][player->x + 1] = 'P';
        char_tab[player->y][player->x] = ' ';
    } else if (char_tab[player->y][player->x + 1] == 'X'
    && (char_tab[player->y][player->x + 2] == ' '
    || char_tab[player->y][player->x + 2] == 'O')) {
        char_tab[player->y][player->x + 1] = 'P';
        char_tab[player->y][player->x] = ' ';
        char_tab[player->y][player->x + 2] = 'X';
    }
}

void player_down(char **char_tab, char *buffer, player_t *player,
    place_t *place_o)
{
    if (char_tab[player->y + 1][player->x] == ' '
    || char_tab[player->y + 1][player->x] == 'O') {
        char_tab[player->y + 1][player->x] = 'P';
        char_tab[player->y][player->x] = ' ';
    } else if (char_tab[player->y + 1][player->x] == 'X'
    && (char_tab[player->y + 2][player->x] == ' '
    || char_tab[player->y + 2][player->x] == 'O')) {
        char_tab[player->y + 1][player->x] = 'P';
        char_tab[player->y][player->x] = ' ';
        char_tab[player->y + 2][player->x] = 'X';
    }
}

void player_up(char **char_tab, char *buffer, player_t *player,
    place_t *place_o)
{
    if (char_tab[player->y - 1][player->x] == ' '
    || char_tab[player->y - 1][player->x] == 'O') {
        char_tab[player->y - 1][player->x] = 'P';
        char_tab[player->y][player->x] = ' ';
    } else if (char_tab[player->y - 1][player->x] == 'X'
    && (char_tab[player->y - 2][player->x] == ' '
    || char_tab[player->y - 2][player->x] == 'O')) {
        char_tab[player->y - 1][player->x] = 'P';
        char_tab[player->y][player->x] = ' ';
        char_tab[player->y - 2][player->x] = 'X';
    }
}
