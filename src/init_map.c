/*
** EPITECH PROJECT, 2022
** init_map.c
** File description:
** Function : init_map
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

int char_int(char cara)
{
    if (cara == 'A') return 0;
    if (cara == 'B') return 1;
    if (cara == 'C') return 2;
    if (cara == 'D') return 3;
    if (cara == 'E') return 4;
    if (cara == 'F') return 5;
    if (cara == 'G') return 6;
    if (cara == 'H') return 7;
    if (cara == '1') return 0;
    if (cara == '2') return 1;
    if (cara == '3') return 2;
    if (cara == '4') return 3;
    if (cara == '5') return 4;
    if (cara == '6') return 5;
    if (cara == '7') return 6;
    if (cara == '8') return 7;
    return 0;
}

int cherche_sens(char **g_map, int n)
{
    int calc_x = char_int(g_map[n][2]) - char_int(g_map[n][5]);
    int calc_y = char_int(g_map[n][3]) - char_int(g_map[n][6]);
    int calc_x_pos = calc_x;
    int calc_y_pos = calc_y;
    if (calc_x < 0) calc_x_pos = calc_x_pos * -1;
    if (calc_y < 0) calc_y_pos = calc_y_pos * -1;
    if (((calc_x_pos + 1) != (char_int(g_map[n][0]) + 1)) &&
    ((calc_y_pos + 1) != (char_int(g_map[n][0]) + 1))) return 84;
    for (int a = 0; a < n; a++) {
        if (g_map[a][0] == g_map[n][0])
            return 84;
    }
    if (calc_x != 0 && calc_y != 0) return 84;
    if (calc_x > 0 && calc_y == 0) return 1;
    if (calc_x < 0 && calc_y == 0) return 2;
    if (calc_x == 0 && calc_y < 0) return 3;
    if (calc_x == 0 && calc_y > 0) return 4;
    return 0;
}

int load_boat(i_g *info_game, char **g_map, int n)
{
    int sens = cherche_sens(g_map, n);
    if (sens == 84) return 84;
    int x_a = char_int(g_map[n][2]);
    int x_b = char_int(g_map[n][5]);
    int y_a = char_int(g_map[n][3]);
    int y_b = char_int(g_map[n][6]);
    char cara = g_map[n][0];
    if (sens == 1) {
        for (; x_b <= x_a; x_b++)
            info_game->my_map[y_a][x_b] = cara;
    } if (sens == 2) {
        for (; x_b >= x_a; x_a++)
            info_game->my_map[y_a][x_a] = cara;
    } if (sens == 3) {
        for (; y_b >= y_a; y_b--)
            info_game->my_map[y_b][x_a] = cara;
    } if (sens == 4) {
        for (; y_b >= y_a; y_a++)
            info_game->my_map[y_a][x_a] = cara;
    } return 0;
}

int load(i_g *info_game, char *map)
{
    if (my_strlen(map) != 31 && my_strlen(map) != 32) return 84;
    int error = 0;
    for (int n = 0; map[n] != '\0'; n++) {
        if (map[n] != '\n' && map[n] != '\0' && (map[n] < '0' || map[n] > '8')
        && (map[n] < 'A' || map[n] > 'H') && map[n] != ':') return 84;
    }
    char **g_map = my_str_to_word_array(map);
    for (int n = 0; g_map[n] != NULL && n < 4; n++) {
        if (g_map[n][0] < '1' || g_map[n][0] > '5') return 84;
        if (g_map[n][1] != ':') return 84;
        if (g_map[n][2] < 'A' || g_map[n][2] > 'H') return 84;
        if (g_map[n][3] < '1' || g_map[n][3] > '8') return 84;
        if (g_map[n][4] != ':') return 84;
        if (g_map[n][5] < 'A' || g_map[n][0] > 'H') return 84;
        if (g_map[n][6] < '1' || g_map[n][0] > '8') return 84;
        if (my_strlen(g_map[n]) != 7) return 84;
        error = load_boat(info_game, g_map, n);
        if (error == 84) return 84;
    } return 0;
}

int init_map(i_g *info_game, int player, char **av)
{
    info_game->my_map = malloc(sizeof(char *) * 10);
    for (int n = 0; n < 9; n++) {
        info_game->my_map[n] = malloc(sizeof(char) * 9);
        fill(info_game->my_map[n], 8);
    } info_game->my_map[9] = NULL;
    if (player == 1) {
        char *map = open_file(av[1]);
        if (map[0] == '8') return 84;
        int error = load(info_game, map);
        if (error == 84) return 84;
    } if (player == 2) {
        char *map = open_file(av[2]);
        if (map[0] == '8') return 84;
        int error = load(info_game, map);
        if (error == 84) return 84;
    } info_game->enemy_map = malloc(sizeof(char *) * 10);
    for (int n = 0; n < 9; n++) {
        info_game->enemy_map[n] = malloc(sizeof(char) * 9);
        fill(info_game->enemy_map[n], 8);
    } info_game->enemy_map[9] = NULL; return 0;
}
