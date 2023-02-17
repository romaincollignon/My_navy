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

void code_sign(int sign)
{
    if (sign == 10) info_game->hit_a++;
    if (sign == 12) info_game->hit_b++;
}

int cherch_sign(i_g *info_game, int pos)
{
    if (pos == 1) {
        while (info_game->hit_b == 0) {
            signal(10, &code_sign);
            signal(12, &code_sign);
        } int result = info_game->hit_a;
        info_game->hit_a = 0;
        return result;
    }
    if (pos == 2) {
        while (info_game->hit_a == 0) {
            pause();
            signal(10, &code_sign);
            signal(12, &code_sign);
        } int result = info_game->hit_b;
        info_game->hit_a = 0;
        info_game->hit_b = 0;
        return result;
    }
    return 1;
}

char pass_char_wait(int hit, int pos)
{
    if (pos == 1) {
        if (hit == 1) return 'A';
        if (hit == 2) return 'B';
        if (hit == 3) return 'C';
        if (hit == 4) return 'D';
        if (hit == 5) return 'E';
        if (hit == 6) return 'F';
        if (hit == 7) return 'G';
        if (hit == 8) return 'H';
    } else {
        return (hit + 48);
    }
    return '#';
}

char *verif_hit(int hit_a, int hit_b, i_g *info_game)
{
    int error = 0;
    usleep(1000);
    if (info_game->my_map[hit_b - 1][hit_a - 1] == 'o') {
        error = kill(info_game->pid, 12);
        if (error == -1) return "84";
        return "missed";
    }
    if (info_game->my_map[hit_b - 1][hit_a - 1] != '.' &&
    info_game->my_map[hit_b - 1][hit_a - 1] != 'x') {
        (info_game->my_map[hit_b - 1][hit_a - 1] = 'x');
        error = kill(info_game->pid, 10);
        if (error == -1) return "84";
        return "hit";
    } else {
        if ((info_game->my_map[hit_b - 1][hit_a - 1] != 'x'))
            (info_game->my_map[hit_b - 1][hit_a - 1] = 'o');
        error = kill(info_game->pid, 12);
        if (error == -1) return "84";
        return "missed";
    }
}

int waiting(i_g *info_game)
{
    mini_printf("\nwaiting for enemy's attack...\n");
    int hit_a = cherch_sign(info_game, 1);
    char hit_char_a = pass_char_wait(hit_a, 1);
    int hit_b = cherch_sign(info_game, 2);
    char hit_char_b = pass_char_wait(hit_b, 2);
    char *result = verif_hit(hit_a, hit_b, info_game);
    if (result[0] == '8') return 84;
    mini_printf("%c%c: %s\n\n", hit_char_a, hit_char_b, result);
    return 0;
}
