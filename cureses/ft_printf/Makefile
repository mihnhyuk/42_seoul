# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 03:36:18 by minhjang          #+#    #+#              #
#    Updated: 2022/04/01 22:32:12 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra
FSAN = -fsanitize=address
OBJECT = $(SRCS:%.c=%.o)
SRCPATH = ./src/
LIBPATH = ./libft/
LIB = $(LIBPATH)libft.a
NAME = libftprintf.a

SRCS =	ft_printf.c \
		$(SRCPATH)utils.c \
		$(SRCPATH)var_to_token.c \
		$(SRCPATH)var_to_token2.c \

INCLUDE = ./includes/ft_printf.h $(LIBPATH)libft.h

.SUFFIXES: .c .o

.PHONY: all clean fclean re test

$(NAME) : $(OBJECT) $(LIB)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJECT)

$(LIB) :
	cd $(LIBPATH) && $(MAKE) all

$(OBJECT) :
	$(CC) $(CFLAGS) -c $(@:.o=.c) -o $@ -L./libft -lft


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
