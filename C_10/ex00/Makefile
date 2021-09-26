# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 22:05:39 by minhjang          #+#    #+#              #
#    Updated: 2021/09/25 22:14:15 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_display_file.c
OBJECT = $(SRC:.c=.o)
NAME = ft_display_file
CC = gcc
CFLAGS = -Wall -Werror -Wextra

.PHONY : clean fclean all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJECT)
	    $(CC) $(CFLAGS) $(OBJECT) -o $(NAME)


all : $(NAME)

clean :
	rm -f $(OBJECT)
fclean : clean
	rm -f $(NAME)

