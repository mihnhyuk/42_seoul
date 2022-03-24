# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 03:36:18 by minhjang          #+#    #+#              #
#    Updated: 2022/03/25 03:47:21 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJECT = $(SRCS:%.c=%.o)
LIBPATH = ./src/
TARGET = libftprintf.a

SRCS =	ft_printf.c \
		utils.c \
		var_to_token.c \


TEST =	main.c \
		var_to_token.c \
		$(LIBPATH)ft_int_length.c \
		$(LIBPATH)ft_strdup.c \

INCLUDE = ft_printf.h ./src/libft.h

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(TARGET)

clean:
	rm -f $(OBJECT)
fclean: clean
	rm -f $(TARGET)
re: fclean all

test:
	$(CC) $(CFLAGS) $(TEST) -include $(INCLUDE)
