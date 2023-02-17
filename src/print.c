/*
** EPITECH PROJECT, 2022
** print.c
** File description:
** Function : print_credit
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "../include/struct_all.h"
#include "my.h"

extern i_g *info_game;

void print_credit(void)
{
mini_printf("USAGE\n");
mini_printf("    ./navy [first_player_pid] navy_positions\n");
mini_printf("DESCRIPTION\n");
mini_printf("    first_player_pid: only for the 2nd player. pid of the first ");
mini_printf("player.\n    ");
mini_printf("navy_positions: file representing the positions of the ships.");
}

void print_map(i_g *info_game)
{
    mini_printf("my positions:\n |A B C D E F G H\n-+---------------\n");
    for (int height = 1; height < 9; height++) {
        mini_printf("%i|", height);
        int l = 0;
        for (; info_game->my_map[height - 1][l] != '\0'; l++)
            mini_printf("%c ", info_game->my_map[height - 1][l]);
        mini_printf("%c\n", info_game->my_map[height - 1][l]);
    }
    mini_printf("\nenemy’s positions:\n |A B C D E F G H\n-+---------------\n");
    for (int height = 1; height < 9; height++) {
        mini_printf("%i|", height);
        int l = 0;
        for (; info_game->enemy_map[height - 1][l] != '\0'; l++)
            mini_printf("%c ", info_game->enemy_map[height - 1][l]);
        mini_printf("%c\n", info_game->enemy_map[height - 1][l]);
    }
}
