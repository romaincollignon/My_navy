/*
** EPITECH PROJECT, 2022
** struct_menu.h
** File description:
** struct for all game
*/

#ifndef STRUCT_MENU_H
    #define STRUCT_MENU_H

    typedef struct info_game {
        char** av;
        int pos;
        int pid;
        int win;
        char **my_map;
        char **enemy_map;
        int tmp_env;
        int tmp_rec;
        int hit_a;
        int hit_b;
    } i_g;

    typedef struct info_child {
        char** av;
        int pid;
        int pos;
        int win;
    } i_c;

    typedef struct info_parent {
        char** av;
        int pid;
        int pos;
        int win;
    } i_p;

#endif /* !STRUCT_MENU_H */
