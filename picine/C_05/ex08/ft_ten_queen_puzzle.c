/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queen_puzzle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:10:14 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/20 13:47:18 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check(int x, char y, char *board);
void	put_next_queen(int x, char *board, int *counter);


int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	 int	counter;
	 
	 counter = 0;
	 while (counter < 10)
		 board[counter++] ='.';
	 counter = 0;
	 put_next_queen(-1, board, &counter);
	 return (counter);	
}

int	check(int x, char y, char *board)
{
	int	idx;

	if (x == -1)
		return (1);
	idx = 0;
	while (idx < x)
	{
		if (board[idx] == y)
			return (0);
		idx++;
	}
	idx = 1;
	while (x - idx >= 0)
	{
		if ( board[x - idx] == y - idx || board[x - idx] == y + idx)
			return (0);
		idx++;
	}
	return (1);

}

void	put_next_queen(int x, char *board, int *counter)
{
	char	y;

	y = '0';
	if (x == 9)
	{
		write(1, board, 10);
		write(1, "\n", 1);
		(*counter)++;
		return ;
	}
	while (y <= '9')
	{
		board[x + 1] = y;
		if (check(x + 1, y, board))
		{
			put_next_queen(x + 1, board, counter);
		}
		y++;
	}
	board[x + 1] = '.';
}
