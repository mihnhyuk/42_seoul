# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 17:07:33 by minhjang          #+#    #+#              #
#    Updated: 2021/12/22 17:07:34 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_etc.c ft_isfunct.c ft_itoa.c ft_memfunct.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_string.c ft_string2.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_tofunct.c
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJECT = $(SRCS:%.c=%.o)

TARGET = libft.a

.SUFFIXES : .c .o

.PHONY: all clean fclean re

$(TARGET) : $(OBJECT)
	ar rc $(TARGET) $(OBJECT)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(TARGET)

clean:
	rm -f $(OBJECT)
fclean: clean
	rm -f $(TARGET)
re: fclean all
