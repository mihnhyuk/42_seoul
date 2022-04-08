# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 03:36:18 by minhjang          #+#    #+#              #
#    Updated: 2022/03/30 17:20:49 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Werror -Wall -Wextra
FSAN = -fsanitize=address
OBJECT = $(SRCS:%.c=%.o)
LIBPATH = ./libft
LIB = ft
NAME = libftprintf.a

SRCPATH = ./srcs/
SRCS =	ft_printf.c \
		$(SRCPATH)utils.c \
		$(SRCPATH)var_to_token.c \
		$(SRCPATH)var_to_token2.c \

INCLUDE = -I./includes

.SUFFIXES: .c .o

.PHONY: all clean fclean re test


$(NAME) : $(OBJECT)
	ar rc $(NAME) $(OBJECT) -L$(LIBPATH) -l$(LIB)

$(OBJECT) : $(SRCS) $(LIB)
	$(CC) $(CFLAGS) $(@.o:.c) -includes $(INCLUDE)

$(LIB) :
	cd $(LIBPATH) && $(MAKE) all

all: $(NAME)
clean:
	rm -f $(OBJECT)
	cd $(LIBPATH) && $(MAKE) clean
fclean: clean
	rm -f $(NAME)
	cd $(LIBPATH) && $(MAKE) fclean
re: fclean all

test: re
	$(CC) $(CFLAGS) main.c -L. -lftprintf
