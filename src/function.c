/*
** EPITECH PROJECT, 2022
** function.c
** File description:
** Function : open_file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <signal.h>

#include "../include/struct_all.h"
#include "my.h"

extern i_g *info_game;

char *open_file(char *adress)
{
    int adresse = open(adress, O_RDONLY);
    if (adresse == -1) {
        close(adresse);
        return "84";
    }
    close(adresse);
    char *file = malloc(sizeof(char) * 50);
    int fd = open(adress, O_RDONLY);
    if (fd == -1) return "84";
    int size_file = read(fd, file, 49);
    if (size_file == -1) return "84";
    if (size_file == 0 || size_file == 1) return "84";
    file[size_file] = '\0';
    close(fd);
    return file;
}

void fill(char *str, int size)
{
    for (int n = 0; n < size; n++)
        str[n] = '.';
    str[size] = '\0';
}
