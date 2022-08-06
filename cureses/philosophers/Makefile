# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 03:36:18 by minhjang          #+#    #+#              #
#    Updated: 2022/08/04 12:13:17 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra -lpthread
FSAN = -fsanitize=address
OBJECT = $(SRCS:%.c=%.o)

LIBPATH = ./libft
LIB = libftprintf.a
NAME = philo

SRCS =	philo.c \
		utils.c \
		table.c		

INCLUDE = $(LIBPATH)libft.h

.SUFFIXES: .c .o

.PHONY: all clean fclean re test

$(NAME) : $(OBJECT) $(LIB)
	$(CC) $(CFLAGS) -L$(LIBPATH) -lftprintf $(OBJECT) -o $(NAME)

$(LIB) :
	cd $(LIBPATH) && $(MAKE) all

$(OBJECT) :
	$(CC) $(CFLAGS) -c $(@:.o=.c) -o $@

all: $(NAME)

clean:
	rm -f $(OBJECT)
	cd $(LIBPATH) && $(MAKE) clean

fclean: clean
	$(MAKE) clean
	rm -f $(NAME)
	cd $(LIBPATH) && $(MAKE) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

test: re
	$(CC) $(CFLAGS) main.c -L. -lftprintf
