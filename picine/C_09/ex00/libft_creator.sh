#! /bin/bash

gcc -Werror -Wextra -Wall -c ft_putchar.c
gcc -Werror -Wextra -Wall -c ft_swap.c
gcc -Werror -Wextra -Wall -c ft_putstr.c
gcc -Werror -Wextra -Wall -c ft_strlen.c
gcc -Werror -Wextra -Wall -c ft_strcmp.c

ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

rm -f ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
