# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 13:21:56 by minhjang          #+#    #+#              #
#    Updated: 2022/06/29 16:31:44 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJECT = $(SRCS:%.c=%.o)
INCLUDE = get_next_line.h\
	so_long.h\
	str_ary.h
NAME = so_long

SRCS = 	main.c\
	ft_strdup.c\
	get_next_line_utils.c\
	get_next_line.c\
	input.c\
	str_ary.c
		
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
	$(MAKE) clean
	rm -f $(NAME)
re: fclean all
	$(MAKE) fclean
	$(MAKE) all

test:
	$(CC) -fsanitize=address -g $(SRCS) -o $(NAME)
