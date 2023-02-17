/*
** EPITECH PROJECT, 2022
** envoi_hit.c
** File description:
** Function : envoi_hit
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "../include/struct_all.h"
#include "my.h"

extern i_g *info_game;

int pass_int_env(char *hit, int pos)
{
    if (pos == 1) {
        if (hit[0] == 'A') return 1;
        if (hit[0] == 'B') return 2;
        if (hit[0] == 'C') return 3;
        if (hit[0] == 'D') return 4;
        if (hit[0] == 'E') return 5;
        if (hit[0] == 'F') return 6;
        if (hit[0] == 'G') return 7;
        if (hit[0] == 'H') return 8;
    } else {
        return (hit[1] - 48);
    }
    return 0;
}

int envoi_hit(i_g *info_game, char *hit)
{
    int error = 0;
    int pos_1 = pass_int_env(hit, 1);
    int pos_2 = pass_int_env(hit, 2);
    for (int nb = 0; nb < pos_1; nb++) {
        usleep(1000);
        error = kill(info_game->pid, 10);
        if (error == -1) return 84;
    }
    for (int nb = 0; nb < pos_2; nb++) {
        usleep(1000);
        error = kill(info_game->pid, 12);
        if (error == -1) return 84;
    }
    usleep(1000);
    error = kill(info_game->pid, 10);
    if (error == -1) return 84;
    return 0;
}
