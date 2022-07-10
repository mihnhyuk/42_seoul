# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 13:21:56 by minhjang          #+#    #+#              #
#    Updated: 2022/07/10 17:06:48 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJECT = $(SRCS:%.c=%.o)
INC_PATH = ./mlx
INCLUDE = get_next_line.h\
	so_long.h\
	str_ary.h\
	$(INC_PATH)/mlx.h
LIB = $(INC_PATH)/mlx
NAME = so_long

SRCS = 	main.c\
	input.c\
	ft_strdup.c\
	get_next_line.c\
	get_next_line_utils.c\
	str_ary.c\
	draw_map.c
	
		
.SUFFIXES : .c .o

.PHONY: all clean fclean re

$(NAME) : $(OBJECT)
	$(CC) $(OBJECT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJECT) : $(SRCS)
	$(CC) $(CFLAGS) -Imlx -c $(@:.o=.c) -o $@


all: $(NAME)

clean:
	rm -f $(OBJECT)

fclean:
	$(MAKE) clean
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all

test:
	$(CC) -fsanitize=address -g $(SRCS) -o $(NAME)
