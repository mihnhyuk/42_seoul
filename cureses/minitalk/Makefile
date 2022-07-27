# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 03:36:18 by minhjang          #+#    #+#              #
#    Updated: 2022/07/27 21:29:42 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra
FSAN = -fsanitize=address
OBJECT = $(SRCS:%.c=%.o)

SRCPATH = ./src/
LIBPATH = ./libft/
LIB = $(LIBPATH)libft.a
NAME = server\
		client

CLIENTPATH = ./clientsrc/
CLIENT = $(CLIENTPATH)client.c
SERVERPATH = ./serversrc/
SERVER = $(SERVERPATH)server.c

SRCS =	$(CLIENT)\
		$(SERVER)

INCLUDE = $(LIBPATH)libft.h

.SUFFIXES: .c .o

.PHONY: all clean fclean re test

$(NAME) : $(OBJECT) $(LIB)
	

$(LIB) :
	cd $(LIBPATH) && $(MAKE) all

$(OBJECT) :
	$(CC) $(CFLAGS) -c $(@:.o=.c) -o $@

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
