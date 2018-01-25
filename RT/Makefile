# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbesse <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:59:01 by cbesse            #+#    #+#              #
#    Updated: 2018/01/25 13:46:18 by esuits           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
SRC = cam.c light.c main.c matop.c plan.c ray.c sp_mat.c sphere.c vect.c 
OBJ = $(SRC:.c=.o)
FRAME = -lmlx -framework OpenGL -framework AppKit
LIB = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -Ofast

all : $(NAME)

$(NAME) : $(OBJ)
	@cd libft && make
	@cd minilibx_macos && make
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ) -Llibft/ -lft $(FRAME)
	@echo "Compilation termine"

%.o : %.c
	@echo "\033[0;36m\033[1ACompilation de $@\033[0m"
	@$(CC) $(FLAGS) -c $<

clean : 
	@rm -rf $(OBJ)
	@cd libft && make clean
	@cd minilibx_macos && make clean
	@echo "\033[1;32mSuppresion des objets ternime\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@cd libft && make fclean
	@cd minilibx_macos && make clean
	@echo "\033[1;32mSuppresion de la librairie\033[0m"

re : fclean all
