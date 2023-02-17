/*
** EPITECH PROJECT, 2022
** envoi_basic.c
** File description:
** Function : cherch_sign
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "../include/struct_all.h"
#include "my.h"

extern i_g *info_game;

int play(i_g *info_game)
{
    int verif = 0;
    while (1) {
        verif = 0;
        mini_printf("attack :");
        char *result = write_term();
        if (result[0] == '8') return 84;
        verif = verif_result(result);
        if (verif == 0) {
            mini_printf("wrong position\n");
        } else {
            envoi_recept(info_game, result);
            break;
        }
    }
}
