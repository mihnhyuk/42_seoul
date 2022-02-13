/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:24:32 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/19 18:59:22 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdlib.h>

void	ft_putnbr(int nb);
void	free_all(int n, int ***view, int ***building);
void	print_result(int n, int **building);

void	output(int n, int ***view, int ***building)
{
	print_result(n, *building);
	free_all(n, view, building);
}

void	ft_putnbr(int nb)
{
	        char	ascii[11];
	         int	idx;
	unsigned int	to_p;

	idx = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		to_p = (unsigned int)(nb * (-1));
	}	
	else
		to_p = (unsigned int)nb;
	while (nb > 9)
	{
		ascii[idx++] = (to_p % 10) + '0';
		to_p /= 10;
	}
	ascii[idx] = (to_p % 10) + '0';
	while (idx >= 0)
	{
		write(1, &ascii[idx--], 1);
	}
}

void	free_all(int n, int ***view, int ***building)
{
	int	idx;

	idx = 0;
	while (idx < 4)
	{
		free((*view)[idx]);
		idx++;
	}
	free(*view);
	idx = 0;
	while (idx < n)
	{
		free((*building)[idx]);
		idx++;
	}
	free(*building);
}

void	print_result(int n, int **building)
{
	int	x;
	int	y;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			ft_putnbr(building[x][y]);
			if (x != n - 1)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
