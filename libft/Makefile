# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 08:44:32 by mbeilles          #+#    #+#              #
#    Updated: 2018/02/15 08:51:39 by mbeilles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  VARIABLES                                   #
#------------------------------------------------------------------------------#
#                                   Naming                                     #
#==============================================================================#

NAME = libft
NICK = "LFT"

#==============================================================================#
#                                 Compilation                                  #
#==============================================================================#

CC = clang

FLAGS = $(HIDDEN_FLAGS) $(FAST_FLAG) $(SLOW_FLAG)
CFLAG = -I$(PATH_INC)
FAST_FLAG = -O3 -march=native -flto
SLOW_FLAG = #-fsanitize=address -g3 -O0

HIDDEN_FLAGS = -v -Weverything \

#==============================================================================#
#                                   Paths                                      #
#==============================================================================#

PATH_SRC = src
PATH_INC = includes
PATH_OBJ = obj

VPATH = $(PATH_SRC):$(PATH_OBJ):$(PATH_INC)

#==============================================================================#
#                                   Various                                    #
#==============================================================================#

SHELL = /bin/sh
MAKE_DEP = 1

#==============================================================================#
#                                   Sources                                    #
#==============================================================================#

DEPENDECIES = \

DEP = \

SRC = ft_atoi.c																\
	  ft_bzero.c															\
	  ft_error.c															\
	  ft_error_exit.c														\
	  ft_get_file_content.c													\
	  ft_get_pow.c															\
	  ft_get_next_line.c													\
	  ft_isspace.c															\
	  ft_isalnum.c															\
	  ft_isalpha.c															\
	  ft_isdigit.c															\
	  ft_isascii.c															\
	  ft_isprint.c															\
	  ft_isset.c															\
	  ft_itoa.c																\
	  ft_lstadd.c															\
	  ft_lstdel.c															\
	  ft_lstdelone.c														\
	  ft_lstinvert_iter.c													\
	  ft_lstiter.c															\
	  ft_lstmap.c															\
	  ft_lstnew.c															\
	  ft_mem_block.c														\
	  ft_mem_block_extension.c												\
	  ft_memalloc.c															\
	  ft_memdup.c															\
	  ft_memcpy.c															\
	  ft_memccpy.c															\
	  ft_memchr.c															\
	  ft_memcmp.c															\
	  ft_memdel.c															\
	  ft_memmove.c															\
	  ft_memset.c															\
	  ft_putstr.c															\
	  ft_putstr_fd.c														\
	  ft_putchar.c															\
	  ft_putchar_fd.c														\
	  ft_putendl.c															\
	  ft_putendl_fd.c														\
	  ft_putnbr.c															\
	  ft_putnbr_fd.c														\
	  ft_realloc.c															\
	  ft_strncpy.c															\
	  ft_strcat.c															\
	  ft_strcdup.c															\
	  ft_strchr.c															\
	  ft_strclr.c															\
	  ft_strlen.c															\
	  ft_strcmp.c															\
	  ft_strcpy.c															\
	  ft_strdel.c															\
	  ft_strdup.c															\
	  ft_strequ.c															\
	  ft_striter.c															\
	  ft_striteri.c															\
	  ft_strjoin.c															\
	  ft_strlcat.c															\
	  ft_strmap.c															\
	  ft_strmapi.c															\
	  ft_strncat.c															\
	  ft_strncmp.c															\
	  ft_strndup.c															\
	  ft_strnequ.c															\
	  ft_strnew.c															\
	  ft_strnstr.c															\
	  ft_strrchr.c															\
	  ft_strsplit.c															\
	  ft_strstr.c															\
	  ft_strsub.c															\
	  ft_strtod.c															\
	  ft_strtol.c															\
	  ft_strtrim.c															\
	  ft_tolower.c															\
	  ft_toupper.c															\
	  ft_t_string_new.c														\
	  ft_t_string_concat.c													\
	  ft_t_string_concat_len.c												\
	  ft_t_string_expand.c													\

INC = libft.h																\
	  get_next_line.h														\

#==============================================================================#
#                                    Vpaths                                    #
#==============================================================================#

vpath %.c $(PATH_SRC)
vpath %.o $(PATH_OBJ)
vpath %.h $(PATH_INC)

#==============================================================================#
#                             Variables Customizers                            #
#==============================================================================#

SRC_O = $(SRC:.c=.o)
ARG_O = $(addprefix $(PATH_OBJ)/,$(notdir $(SRC:.c=.o)))

#==============================================================================#
#                                   Strings                                    #
#==============================================================================#

PROJECT_COLOR = "\033[38;2;243;156;18m"
PROJECT_COLOR_ALT = "\033[38;2;22;160;133m"
PRIMARY_COLOR = "\033[38;2;93;188;210m"
PRIMARY_COLOR_ALT = "\033[38;2;38;106;150m"
SUCCESS_COLOR = "\033[38;2;141;143;38m"
SUCCESS_COLOR_ALT = "\033[38;2;39;174;96m"
ERROR_COLOR = "\033[38;2;231;76;60m"

KO = $(PRIMARY_COLOR_ALT)"["$(ERROR_COLOR)$(BOLD)" - "$(PRIMARY_COLOR_ALT)"] "
OK = $(PRIMARY_COLOR_ALT)"["$(SUCCESS_COLOR)$(BOLD)" + "$(PRIMARY_COLOR_ALT)"] "
HD = $(PRIMARY_COLOR_ALT)"["$(PROJECT_COLOR)$(NICK)$(PRIMARY_COLOR_ALT)"] "

NRM = "\033[0m"

SUCCESS_HD = $(PRIMARY_COLOR_ALT)"["$(PROJECT_COLOR)"SUCCESS"$(PRIMARY_COLOR_ALT)"] "
FAILURE_HD = $(PRIMARY_COLOR_ALT)"["$(PROJECT_COLOR)"FAILURE"$(PRIMARY_COLOR_ALT)"] "

MAKING_PROGRESS = $(OK)$(SUCCESS_COLOR_ALT)"> Genrating "$(NAME)"...\n"$(NRM)
MAKING_SUCCESS = $(SUCCESS_HD)$(SUCCESS_COLOR)$(NAME)" generated!\n"$(NRM)
MAKING_FAILURE = $(FAILURE_HD)$(ERROR_COLOR)$(NAME)" not generated!\n"$(NRM)

COMPILING_OK = $(HD)$(OK)$(PRIMARY_COLOR)"$@\n"$(NRM)
COMPILING_KO = $(HD)$(KO)$(ERROR_COLOR)"* "$(PRIMARY_COLOR)"$@\n"$(NRM)

CLEANING_OBJS = $(HD)$(OK)$(PROJECT_COLOR)"Files cleaned\n"$(NRM)
CLEANING_BINS = $(HD)$(OK)$(PROJECT_COLOR)"Binary cleaned\n"$(NRM)

#==============================================================================#
#	MAKEFILE
#==============================================================================#

$(NAME).a: $(PATH_OBJ) $(SRC_O) | $(INC)
	@printf $(MAKING_PROGRESS)
	@ar rc $(NAME).a $(ARG_O) && ranlib $(NAME).a; \
		if [ $$? != 1 ]; then printf $(MAKING_SUCCESS); exit 0; \
		else printf $(MAKING_FAILURE); exit 2; fi

all: $(NAME).a

%.o: %.c
	@$(CC) -o $(PATH_OBJ)/$@ -c $< $(CFLAG) $(FLAGS); \
		if [ $$? != 1 ]; then printf $(COMPILING_OK); exit 0; \
		else printf $(COMPILING_KO); exit 2; fi

$(PATH_OBJ):
	@mkdir $@

clean:
	@rm -f $(ARG_O)
	@printf $(CLEANING_OBJS)

fclean: clean
	@rm -f $(NAME).a
	@printf $(CLEANING_BINS)

re: fclean all
