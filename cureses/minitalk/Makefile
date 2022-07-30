# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 03:36:18 by minhjang          #+#    #+#              #
#    Updated: 2022/07/30 19:01:59 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra
FSAN = -fsanitize=address
OBJECT = $(OBJECTCLI) $(OBJECTSERV)
OBJECTCLI = $(CLIENTSRC:%.c=%.o)
OBJECTSERV = $(SERVERSRC:%.c=%.o)

SRCPATH = ./src/
LIBPATH = ./libft
LIB = libftprintf.a
NAME = $(SERVER)\
		$(CLIENT)

CLIENTPATH = ./clientsrc/
CLIENTSRC = $(CLIENTPATH)client.c\
			$(CLIENTPATH)send_string.c \
			$(CLIENTPATH)check_receive.c
CLIENT = client
SERVERPATH = ./serversrc/
SERVERSRC = $(SERVERPATH)server.c \
			$(SERVERPATH)sighandler.c \
			$(SERVERPATH)utils.c \
			$(SERVERPATH)decoder.c
SERVER = server


SRCS =	$(CLIENT)\
		$(SERVER)

INCLUDE = $(LIBPATH)libft.h

.SUFFIXES: .c .o

.PHONY: all clean fclean re test

$(NAME) : $(OBJECT) $(LIB)
	$(CC) $(CFLAGS) -L$(LIBPATH) -lftprintf $(OBJECTSERV) -o $(SERVER)
	$(CC) $(CFLAGS) -L$(LIBPATH) -lftprintf $(OBJECTCLI) -o $(CLIENT)

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
