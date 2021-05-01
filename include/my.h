/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my.h
*/

#pragma once
#include "player.h"

int my_strlen(char const *);
char *my_malloc(int);
int count_o(char *);
void get_pos_o(place_t *, char **, char *);
void put_o(char *, char **, place_t *);
char *fs_open_file(char const *, char *, int);
int count_lines(char *);
int count_colums(char *);
void get_pos_x(place_t *, char **, char *);
char **tab_of_char(char *, int);
void player_place(char **, char *, player_t *);
void player_left(char **, char *, player_t *, place_t *);
void player_right(char **, char *, player_t *, place_t *);
void player_down(char **, char *, player_t *, place_t *);
void player_up(char **, char *, player_t *, place_t *);
void events(char **, char *, player_t *, place_t *);
void print_map(char *, char **);
int check_win(place_t *, place_t *, char *);
int display_ncurses(char **, char *, player_t *, place_t *);
int error_handling(char *);
void error(int);
int x_check(char **, place_t *, char *);
void descr(void);
int my_putstr(char const *);
void my_putchar(char);


int is_blocked(char **tab, place_t pos);
int count_x(char *buffer);
