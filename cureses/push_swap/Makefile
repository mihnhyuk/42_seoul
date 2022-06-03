# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 13:21:56 by minhjang          #+#    #+#              #
#    Updated: 2022/06/03 20:29:53 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJECT = $(SRCS:%.c=%.o)

NAME = push_swap

SRCS = 	push_swap.c \
		ft_atoi.c \
		ft_strcmp.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		stack.c	\
		push_function.c \
		push_function2.c \
		push_function3.c \
		get_next_line.c \
		get_next_line_utils.c \
		util.c \
		sort.c \
		qsort.c \
		
.SUFFIXES : .c .o

.PHONY: all clean fclean re

$(NAME) : $(OBJECT)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(OBJECT) :
	$(CC) $(CFLAGS) -c $(@:.o=.c) -o $@

all: $(NAME)

clean:
	rm -f $(OBJECT)

fclean:
	$(MAKE) clean
	rm -f $(NAME)
re: fclean all
	$(MAKE) fclean
	$(MAKE) all

test:
	$(CC) -g $(SRCS) -o $(NAME)
