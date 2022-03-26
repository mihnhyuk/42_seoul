# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 03:36:18 by minhjang          #+#    #+#              #
#    Updated: 2022/03/26 16:12:17 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra
FSAN = -fsanitize=address
OBJECT = $(SRCS:%.c=%.o)
LIBPATH = ./src/
TARGET = libftprintf.a

SRCS =	ft_printf.c \
		utils.c \
		var_to_token.c \
		var_to_token2.c \
		$(LIBPATH)ft_putstr_fd.c \
		$(LIBPATH)ft_strdup.c \
		$(LIBPATH)ft_strlen.c \

INCLUDE = ft_printf.h ./src/libft.h

.SUFFIXES: .c .o

.PHONY: all clean fclean re test

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

test:
	$(CC) $(CFLAGS)  main.c -L. -lftprintf
