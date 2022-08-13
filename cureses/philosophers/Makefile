# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 03:36:18 by minhjang          #+#    #+#              #
#    Updated: 2022/08/11 21:13:18 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra
FSAN = -fsanitize=address
OBJECT = $(SRCS:%.c=%.o)

NAME = philo

SRCS =	philo.c \
		utils.c \
		routine.c \
		ft_atoi.c	

INCLUDE = $(LIBPATH)libft.h

.SUFFIXES: .c .o

.PHONY: all clean fclean re test

$(NAME) : $(OBJECT)
	$(CC) $(CFLAGS) -lpthread $(OBJECT) -o $(NAME)

$(OBJECT) :
	$(CC) $(CFLAGS) -c $(@:.o=.c) -o $@

all: $(NAME)

clean:
	rm -f $(OBJECT)

fclean: clean
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

test: re
	$(CC) $(CFLAGS) main.c -L. -lftprintf
