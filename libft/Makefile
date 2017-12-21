# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esuits <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 12:30:35 by esuits            #+#    #+#              #
#    Updated: 2017/11/16 15:02:44 by esuits           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wextra -Wall

NAME = libft.a

SRCS = ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcpy.c ft_memmove.c \
	   ft_memset.c ft_putchar.c ft_putstr.c ft_strlen.c ft_memcmp.c \
	   ft_strdup.c ft_strcat.c ft_strcmp.c ft_strcpy.c ft_strncat.c \
	   ft_strncmp.c ft_strncpy.c ft_strstr.c ft_strnstr.c ft_strchr.c \
	   ft_strrchr.c ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isprint.c \
	   ft_isascii.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strlcat.c \
	   ft_memdel.c ft_memalloc.c ft_strnew.c ft_striter.c ft_strdel.c \
	   ft_strclr.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	   ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	   ft_showtab.c ft_itoa.c ft_putnbr.c ft_putendl.c ft_putstr_fd.c \
	   ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_lstnew.c \
	   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) -c $(SRCS);
	ar rc $(NAME) $(OBJ);
	ranlib $(NAME);

clean :
	rm -f $(OBJ);

fclean : clean
	rm -f $(NAME);

re : fclean all
