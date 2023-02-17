/*
** EPITECH PROJECT, 2022
** navy.c
** File description:
** Function : navy
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "../include/struct_all.h"
#include "my.h"

i_g *info_game;

int navy_child(i_g *info_game, char **av)
{
    int error = init_map(info_game, 2, av);
    if (error == 84) return 84;
    int child_pid = getpid();
    mini_printf("my_pid: %i\n", child_pid);
    int int_pid = my_getnbr(info_game->av[1]);
    int result = kill(int_pid, 10);
    if (result == 0) {
        mini_printf("successfully connected\n\n");
    } else {
        mini_printf("Failed connection\n");
        return 84;
    }
    info_game->pid = int_pid;
    return game(info_game, 2);
}

void start(int signum, siginfo_t *str, void *obj)
{
    (void)obj;

    if (signum == 10) {
        info_game->pid = str->si_pid;
        mini_printf("\nenemy connected -> %i\n", info_game->pid);
    }
}

int navy_parent(i_g *info_game, char **av)
{
    int error = init_map(info_game, 1, av);
    if (error == 84) return 84;
    struct sigaction sig;
    sig.sa_sigaction = &start;
    sig.sa_flags = SA_SIGINFO;
    int parent_pid = getpid();
    mini_printf("my_pid: %i\nwaiting for enemy connection...\n", parent_pid);
    sigaction(SIGUSR1, &sig, NULL);
    pause();
    return game(info_game, 1);
}

int navy(int pos, char **av)
{
    info_game = malloc(sizeof(i_g));
    init_all(info_game, pos, av);
    if (pos == -1) {
        info_game->pos = 1;
        return navy_parent(info_game, av);
    } if (pos == 1) {
        info_game->pid = my_getnbr(av[2]);
        info_game->pos = 2;
        return navy_child(info_game, av);
    }
    return 0;
}
