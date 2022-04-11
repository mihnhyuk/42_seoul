# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 13:21:56 by minhjang          #+#    #+#              #
#    Updated: 2022/04/11 15:04:40 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJECT = $(SRCS:%.c=%.o)

NAME = push_swap

SRCS = 	push_swap.c \
		ft_atoi.c \
		ft_strcmp.c \
		stack.c	\
		get_next_line.c \
		get_next_line_utils.c \
		get_next_line.h \
		util.c

.SUFFIXES : .c .o

.PHONY: all clean fclean re

$(NAME) : $(OBJECT)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(OBJECT) :
	$(CC) $(CFLAGS) -c $(@:.o=.c) -o $@

all: $(NAME)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)
re: fclean all

test:
	$(CC) $(SRCS)
