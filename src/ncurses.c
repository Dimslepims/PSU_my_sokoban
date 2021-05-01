/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** ncurses function
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

void events(char **char_tab, char *buffer, player_t *player, place_t *place_o)
{
    int c = 0;
    c = getch();
    switch (c) {
        case KEY_LEFT:
            player_left(char_tab, buffer, player, place_o);
            break;
        case KEY_RIGHT:
            player_right(char_tab, buffer, player, place_o);
            break;
        case KEY_DOWN:
            player_down(char_tab, buffer, player, place_o);
            break;
        case KEY_UP:
            player_up(char_tab, buffer, player, place_o);
            break;
    }
}

void print_map(char *buffer, char **map)
{
    int lines = count_lines(buffer);
    int cols;
    int x = 0;
    int y = 0;
    int j = 0;

    for (int i = 0; i < lines; ++i) {
        cols = my_strlen(map[i]);
        for (int j = 0; j < cols; ++j) {
            mvprintw(LINES / 2 + i - 6, COLS / 2 + j - 6, "%c", map[i][j]);
        }
    }
}

int check_win(place_t *place_o, place_t *place_x, char *buffer)
{
    int win = 0;

    for (int i = 0; i < count_o(buffer); ++i) {
        if ((place_o[i].y == place_x[i].y) && (place_o[i].x == place_x[i].x))
            ++win;
    }
    return (win);
}

int display_ncurses(char **map_in_tab, char *buffer, player_t *player,
    place_t *place_o)
{
    place_t *place_x = malloc(sizeof(place_t) * count_o(buffer));
    int w = 0;
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    while (check_win(place_o, place_x, buffer) != count_o(buffer)) {
        print_map(buffer, map_in_tab);
        player_place(map_in_tab, buffer, player);
        events(map_in_tab, buffer, player, place_o);
        get_pos_x(place_x, map_in_tab, buffer);
        if (x_check(map_in_tab, place_x, buffer) == count_o(buffer)) {
            w = 1;
            break;
        }
        put_o(buffer, map_in_tab, place_o);
    }
    print_map(buffer, map_in_tab);
    refresh();
    endwin();
    return (w);
}
