/*
** EPITECH PROJECT, 2022
** main
** File description:
** main -> sokoban
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ncurses.h>

#include "struct_all.h"
#include "my.h"

int error(int ac, char **av, char **env)
{
    if (!env || !env[0])
        return 84;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        print_credit();
        return 0;
    }
    if (ac == 2) return -1;
    if (ac == 3) return 1;
    return 84;
}

int main(int ac, char **av, char **env)
{
    int verif = error(ac, av, env);
    if (verif == 84 || verif == 0) return verif;
    return navy(verif, av);
}
