/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** open & read
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

char *fs_open_file(char const *filepath, char *buffer, int size)
{
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        exit (84);
    int rd = read(fd, buffer, size);
    buffer[rd] = '\0';
    if (rd < 0)
        exit (84);
    return (buffer);
}
