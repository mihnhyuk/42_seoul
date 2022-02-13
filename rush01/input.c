/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:06:54 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/19 22:11:16 by swoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	init_value(int n, int **view, int **building, char *input);
void	set_size(int n, int ***view, int ***building);
int		find_board_size(char *str);

int	input(int *n, int ***view, int ***building, char *str)
{
	*n = find_board_size(str);
	if (*n == 0)
		return (1);
	set_size(*n, view, building);
	init_value(*n, *view, *building, str);
	return (0);
}

void	init_value(int n, int **view, int **building, char *input)
{
	int	idx[2];

	idx[0] = 0;
	while (idx[0] < n)
	{
		idx[1] = 0;
		while (idx[1] < n)
			building[idx[0]][idx[1]++] = 0;
		idx[0]++;
	}
	idx[0] = 0;
	while (idx[0] < 4)
	{
		idx[1] = 0;
		while (idx[1] < n)
		{
			view[idx[0]][idx[1]++] = (*input) - '0' ;
			input += 2;
		}
		idx[0]++;
	}
}

int	find_board_size(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	idx++;
	if (idx % 8 != 0)
		return (0);
	idx /= 8;
	return (idx);
}

void	set_size(int n, int ***view, int ***building)
{
	int	idx;

	idx = 0;
	*view = (int **)malloc(4 * sizeof (int *));
	while (idx < 4)
	{
		(*view)[idx] = (int *)malloc(n * sizeof (int));
		idx++;
	}
	*building = (int **)malloc(n * sizeof (int *));
	idx = 0;
	while (idx < n)
	{
		(*building)[idx] = (int *)malloc(n * sizeof (int));
		idx++;
	}
}
