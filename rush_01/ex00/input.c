/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:06:54 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/18 20:40:52 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	g_n;

void	ft_putnbr(int nb);
void	set_size(int ***view, int ***building);
int	find_board_size(char *str);
void	print_result(int **building);
void	free_all(int ***view, int ***building);
void	init_value(int **view, int **building, char *input);
int	dfs_search(int *pos, int **view, int **building);

int	main(int argc, char *argv[])
{
	int	**building;
	int	**view;
	int	idx[2];
	
	if (argc != 2)
		write(1, "Error\n", 6);
	g_n = find_board_size(argv[1]);
	set_size(&view, &building);
	idx[1] = -1;
	idx[0] = 0;
	init_value(view, building, argv[1]);
	dfs_search(idx ,view, building);
	print_result(building);	
	free_all(&view, &building);
}

void	init_value(int **view, int **building, char *input)
{
	int idx[2];
	
	idx[0] = 0;
	while (idx[0] < g_n)
	{
		idx[1] = 0;
		while (idx[1] < g_n)
			building[idx[0]][idx[1]++] = 0;
		idx[0]++;
	}
	
	idx[0] = 0;
	while (idx[0] < 4)
	{
		idx[1] = 0;
		while (idx[1] < g_n)
		{
			view[idx[0]][idx[1]++] = (*input) - '0' ;
			input += 2;
		}
		idx[0]++;
	}
	
}

void	free_all(int ***view, int ***building)
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
	while (idx < g_n)
	{
		free((*building)[idx]);
		idx++;
	}
	free(*building);
}

void	print_result(int **building)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < g_n)
	{
		x = 0;
		while (x < g_n)
		{
			ft_putnbr(building[x][y]);
			if(x != g_n - 1)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	set_size(int ***view, int ***building)
{
	int	idx;
	int	jdx;

	idx = 0;
	*view = (int **)malloc(4 * sizeof (int *));
	while (idx < 4)
	{
		(*view)[idx] = (int *)malloc(g_n * sizeof (int));
		idx++;
	}
	*building = (int **)malloc(g_n * sizeof (int *));
	idx = 0;
	while (idx < g_n)
	{
		(*building)[idx] = (int *)malloc(g_n * sizeof (int));
		idx++;
	}
}

int	find_board_size(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	idx++;
	idx /= 8;
	return (idx);
}

