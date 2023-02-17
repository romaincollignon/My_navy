/*
** EPITECH PROJECT, 2022
** signal.c
** File description:
** Function : cherch_sign
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "../include/struct_all.h"
#include "my.h"

extern i_g *info_game;

int verif_attack(char *result)
{
    if (result == NULL) return 84;
    if (result[0] != 'A' && result[0] != 'B' && result[0] != 'C' && result[0] !=
    'D' && result[0] != 'E' && result[0] != 'F' && result[0] != 'G' && result[0]
    != 'H') return 0;
    if (result[1] != '1' && result[1] != '2' && result[1] != '3' && result[1] !=
    '4' && result[1] != '5' && result[1] != '6' && result[1] != '7'
    && result[1] != '8') return 0;
    if (result[2] != '\n') return 0;
    return 1;
}

char *attack(void)
{
    mini_printf("\n");
    int tmp = 0;
    while (1) {
        mini_printf("attack: ");
        char *term = write_term();
        if (term[0] == '8') return "84";
        tmp = verif_attack(term);
        if (tmp == 1) {
            term[3] = '\0';
            return term;
        }
        if (tmp == 84)
            return "84";
        mini_printf("wrong position\n");
    }
}

void sign_hit(int sign)
{
    if (sign == 10)
        info_game->tmp_env = 1;
    if (sign == 12)
        info_game->tmp_env = 0;
}

int recep_hit(void)
{
    while (info_game->tmp_env == -1)  {
        signal(10, sign_hit);
        signal(12, sign_hit);
    }
    if (info_game->tmp_env == 1) {
        info_game->tmp_env = -1;
        return 1;
    } else {
        info_game->tmp_env = -1;
        return 0;
    }
    return 0;
}

int envoi(i_g *info_game, char *hit)
{
    int error = envoi_hit(info_game, hit);
    if (error == 84) return 84;
    int result = recep_hit();
    hit[2] = '\0';
    if (result == 1) {
        mini_printf("%s: hit\n\n", hit);
        int pos_a = pass_int_env(hit, 1);
        int pos_b = pass_int_env(hit, 2);
        info_game->enemy_map[pos_b - 1][pos_a - 1] = 'x';
        return 0;
    } else {
        mini_printf("%s: missed\n\n", hit);
        int pos_a = pass_int_env(hit, 1);
        int pos_b = pass_int_env(hit, 2);
        if (info_game->enemy_map[pos_b - 1][pos_a - 1] != 'x')
            info_game->enemy_map[pos_b - 1][pos_a - 1] = 'o';
        return 0;
    }
}
