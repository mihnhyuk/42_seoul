# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 16:03:59 by minhjang          #+#    #+#              #
#    Updated: 2021/09/26 18:47:59 by minhjang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c file_input.c
OBJ = main.o file_input.o
CC = gcc
CFLAGS = -Werror -Wall -Wextra
TARGET = rush-02



$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $^
$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $^ -o $@
