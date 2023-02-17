/*
** EPITECH PROJECT, 2022
** verif_win.c
** File description:
** Function : verif_win
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "../include/struct_all.h"
#include "my.h"

extern i_g *info_game;

int verif_boat(char boat, int nb_boat)
{
    if (boat == '1' || boat == '2' || boat == '3' || boat == '4' || boat == '5')
        nb_boat = nb_boat + 1;
    return nb_boat;
}

int verif_boat_enemy(char boat, int nb_boat)
{
    if (boat == 'x')
        nb_boat = nb_boat + 1;
    return nb_boat;
}

int verif_win(i_g *info_game)
{
    int nb_boat = 0;
    for (int n = 0; n < 8 && info_game->my_map[n] != NULL; n++) {
        for (int a = 0; a < 8 && info_game->my_map[n][a] != '\0'; a++)
            nb_boat = verif_boat(info_game->my_map[n][a], nb_boat);
    }
    if (nb_boat == 0) {
        mini_printf("\nEnemy won\n");
        return 1;
    }
    int nb_boat_enemy = 0;
    for (int n = 0; n < 8 && info_game->enemy_map[n] != NULL; n++) {
        for (int a = 0; a < 8 && info_game->enemy_map[n][a] != '\0'; a++)
            nb_boat_enemy = verif_boat_enemy(info_game->enemy_map[n][a],
            nb_boat_enemy);
    }
    if (nb_boat_enemy == 14) {
        mini_printf("\nI won\n");
        return 1;
    }
    return 0;
}
