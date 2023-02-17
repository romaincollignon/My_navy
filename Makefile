##
## EPITECH PROJECT, 2017
## makefile
## File description:
## task01
##

SRC 	=	src/function/mini_printf.c \
			src/function/my_put_nbr.c \
			src/function/my_putchar.c \
			src/function/my_putstr.c \
			src/function/my_compute_power_rec.c \
			src/function/my_revstr.c \
			src/function/my_str_to_word_array.c \
			src/function/my_getnbr.c \
			src/print.c \
			src/init.c \
			src/init_map.c \
			src/game.c \
			src/navy.c \
			src/function.c \
			src/envoi.c \
			src/reception.c \
			src/verif_win.c \
			src/envoi_hit.c \
			src/main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I ./include/ -g

NAME	=	navy

all:	$(NAME)

$(NAME): $(OBJ)
	@echo -e "🔨 \033[0;32mCompile navy \033[0;30m🔨"
	gcc $(OBJ) $(CFLAGS) -o $(NAME) -lncurses
	@echo -e "✅ \033[0;31mNavy compiled ✅ \033[0m"

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug :
	gcc $(SRC) -Wall -Wextra -I include -o $(NAME) -g $(CFLAGS)

.PHONY:	all clean fclean re
