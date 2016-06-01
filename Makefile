# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mroturea <mroturea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/31 20:43:27 by mroturea          #+#    #+#              #
#    Updated: 2016/06/01 16:19:11 by mroturea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

NAME = fractol

CC = gcc

LIB = libft/libft.a

FLAG = -Wall -Wextra -Werror -O3

LIBGRPH = -lmlx -framework OpenGL -framework Appkit

INC = fractol.h

OBJ =  julia.o fractol.o tricorn.o mandel.o medusa.o commande.o

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		@$(CC) $(FLAG) $(OBJ) $(LIB) -o $(NAME) $(LIBGRPH)

$(LIB):
		@echo "\033[33mLibft compilation\033[0m"
		@make -C libft/
		@echo "\033[33mProject compilation\033[0m"
		@echo "\033[32mCompilation SUCCESS\033[0m"

%.o : %.c $(INC)
		@$(CC) -c $(FLAG) $< -o $@

clean:
				@echo "\033[33m.o's cleaning\033[0m"
				@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft/
		@rm -rf $(NAME)

re: fclean all
