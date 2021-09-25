# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 14:59:16 by minhjang          #+#    #+#              #
#    Updated: 2021/09/25 12:41:19 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
INCLUDE = ./includes
CFLAGS = -Wall -Wextra -Werror
SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
NAME = libft.a
OFILES = ./srcs/ft_putchar.o ./srcs/ft_putstr.o ./srcs/ft_strcmp.o ./srcs/ft_strlen.o ./srcs/ft_swap.o



.PHONY: clean fclean all re .c.o

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(NAME) : $(OFILES)
	ar rc $(NAME) $(OFILES)
$(OFILES) : $(SRC)
	      $(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)


all: $(NAME)

clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all

