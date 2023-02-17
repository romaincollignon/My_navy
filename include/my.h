/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** all prototypes and include
*/

#ifndef MY_H_
    #define MY_H_
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <signal.h>

    #include "struct_all.h"
    #include "my.h"

    // Function :
    int mini_printf(const char *format, ...);
    char **read_file(char *av[]);
    int mini_printf(const char *format, ...);
    int printf_credit(int tmp);
    int my_strlen(char const *str);
    char *my_put_nbr_modif(int nb);
    int	my_getnbr(char const *str);
    int my_power(int nb, int p);
    char **my_double_tab(char *buffer, char separator);
    int my_strcmp(char const *s1, char const *s2);
    char *my_put_nbr_modif(int nb);
    char *my_put_nbr_double(int nb);
    char *my_revstr(char *str);
    char* my_inv_double_tab(char** txt);
    char* my_inv_double_tab_html(char** txt);
    char *my_strcpy(char *dest, char const *src);
    char **my_str_to_word_array(char *b_tab);
    void fill(char *str, int size);
    char pass_char_wait(int hit, int pos);

    // Navy :
    int navy(int pos, char **av);
    int game(i_g *info_game, int player);
    int cherch_sign(i_g *info_game, int pos);

    // Envoi :
    int envoi(i_g *info_game, char *hit);
    char *write_term(void);
    char *attack(void);
    int envoi_hit(i_g *info_game, char *hit);
    int pass_int_env(char *hit, int pos);

    // Receptin :
    int waiting(i_g *info_game);

    // Verif_win :
    int verif_win(i_g *info_game);

    // Print :
    void print_credit(void);
    void print_map(i_g *info_game);

    // Init :
    int init_all(i_g *info_game, int pos, char **av);
    int init_map(i_g *info_game, int player, char **av);
    char *open_file(char *adress);

    // Error :
    int error(int ac, char **av, char **env);

#endif /* !MY_H_ */
