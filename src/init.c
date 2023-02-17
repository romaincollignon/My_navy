/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** Function : init_all
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

int init_all(i_g *info_game, int pos, char **av)
{
    info_game->pos = pos;
    info_game->win = 14;
    info_game->av = av;
    info_game->pid = 0;
    info_game->tmp_env = -1;
    info_game->tmp_rec = -1;
    info_game->hit_a = 0;
    info_game->hit_b = 0;
    return 0;
}
