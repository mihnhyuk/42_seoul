# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 00:00:34 by minhjang          #+#    #+#              #
#    Updated: 2021/09/30 00:00:36 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = do-op.c ft_atoi.c ft_nbr.c operation.c
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJECT = $(SRCS_C:.c=.o)

TARGET = do-op

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

.PHONY : all clean fclean re

all : $(TARGET)

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(TARGET)

re: fclean all
