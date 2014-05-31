# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lverniss <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/18 03:45:31 by lverniss          #+#    #+#              #
#    Updated: 2014/04/20 14:50:46 by lverniss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ls

SRCS	=	libc/ft_bzero.c libc/ft_putnbr.c libc/ft_nblen.c\
			libc/ft_strlen.c libc/ft_strdup.c libc/ft_memalloc.c\
			libc/ft_error.c	src/main.c src/mask.c src/print_hash.c\
			src/ft_insert.c src/free_hash.c src/print.c src/concat.c\
			src/recur.c src/write_s.c src/biglen.c src/init.c\
			src/push.c src/hidden.c src/dirs.c\

SRC	= $(addprefix $(SRCPATH), $(SRCS))

OBJ	= $(SRC:.c=.o)

TEST	= src/main.o

CFLAGS	+=  -Wall -Wextra -Werror -I include

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "\033[1;32m[ $(NAME) Created ]\033[1;32m"

clean :
	@if test -f $(TEST) ;then \
		rm -f $(OBJ) && echo "\033[1;32m[ OBJCLEAN : DONE ]\033[0;00m"; \
		else echo "\033[1;31m[ OBJCLEAN : file not exist ]\033[0;00m"; \
		fi

fclean : clean
	@if test -e $(NAME) ;then \
		rm -f $(NAME) && echo "\033[1;32m[ BINCLEAN : DONE ]\033[0;00m"; \
		else echo "\033[1;31m[ BINCLEAN : file not exist ]\033[0;00m"; \
		fi

re: fclean all

.PHONY: all clean fclean re
