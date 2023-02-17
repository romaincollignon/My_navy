/*
** EPITECH PROJECT, 2022
** game.c
** File description:
** Function : game
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "../include/struct_all.h"
#include "my.h"

extern i_g *info_game;

char *write_term(void)
{
    size_t line = 0;
    char *buffer = NULL;
    int error = 0;
    error = getline(&buffer, &line, stdin);
    if (error == -1)
        return ("84");
    return buffer;
}

int game(i_g *info_game, int player)
{
    int error = 0;
    print_map(info_game);
    if (player == 1) {
        char *hit = attack();
        if (hit[0] == '8') return 84;
        error = envoi(info_game, hit);
        if (error == 84) return 84;
        print_map(info_game);
    } while (1) {
        error = waiting(info_game);
        if (error == 84) return 84;
        print_map(info_game);
        if (verif_win(info_game) == 1) return 0;
        char *hit = attack();
        if (hit[0] == '8') return 84;
        error = envoi(info_game, hit);
        if (error == 84) return 84;
        print_map(info_game);
        if (verif_win(info_game) == 1) return 0;
    } return 0;
}
