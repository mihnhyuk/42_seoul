/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:08:34 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/19 16:01:28 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_left(int n, int *pos, int **view, int **building);
int	check_right(int n, int *pos, int **view, int **building);
int	check_up(int n, int *pos, int **view, int **building);
int	check_down(int n, int *pos, int **view, int **building);

int	possible(int n, int *pos, int **view, int **building)
{
	int	idx;

	idx = 0;
	while (idx < pos[1])
	{
		if (building[pos[0]][idx] == building[pos[0]][pos[1]])
			return (0);
		idx++;
	}
	if (check_left(n, pos, view, building)
		&& check_right(n, pos, view, building)
		&& check_up(n, pos, view, building)
		&& check_down(n, pos, view, building))
		return (1);
	else
		return (0);
}

int	check_left(int n, int *pos, int **view, int **building)
{
	int	max;
	int	count_max;
	int	count_min;
	int	idx;

	max = -1;
	count_max = 0;
	count_min = 0;
	idx = 0;
	while (idx < n)
	{
		if (max <= building[idx][pos[1]])
		{
			count_max++;
			if (max < building[idx][pos[1]])
				count_min++;
			max = building[idx][pos[1]];
		}
		idx++;
	}
	if (view[2][pos[1]] >= count_min && view[2][pos[1]] <= count_max)
		return (1);
	else
		return (0);
}

int	check_right(int n, int *pos, int **view, int **building)
{
	int	max;
	int	count_max;
	int	count_min;
	int	idx;

	max = -1;
	count_max = 0;
	count_min = 0;
	idx = n - 1;
	while (idx >= 0)
	{
		if (max <= building[idx][pos[1]])
		{
			count_max++;
			if (max < building[idx][pos[1]])
				count_min++;
			max = building[idx][pos[1]];
		}
		idx--;
	}
	if (view[3][pos[1]] >= count_min && view[3][pos[1]] <= count_max)
		return (1);
	else
		return (0);
}

int	check_up(int n, int *pos, int **view, int **building)
{
	int	max;
	int	count_max;
	int	count_min;
	int	idx;

	max = -1;
	count_max = 0;
	count_min = 0;
	idx = 0;
	while (idx < n)
	{
		if (max <= building[pos[0]][idx])
		{
			count_max++;
			if (max < building[pos[0]][idx])
				count_min++;
			max = building[pos[0]][idx];
		}
		idx++;
	}
	if (view[0][pos[0]] >= count_min && view[0][pos[0]] <= count_max)
		return (1);
	else
		return (0);
}

int	check_down(int n, int *pos, int **view, int **building)
{
	int	max;
	int	count_max;
	int	count_min;
	int	idx;

	max = -1;
	count_max = 0;
	count_min = 0;
	idx = n - 1;
	while (idx >= 0)
	{
		if (max <= building[pos[0]][idx])
		{
			count_max++;
			if (max < building[pos[0]][idx])
				count_min++;
			max = building[pos[0]][idx];
		}
		idx--;
	}
	if (view[1][pos[0]] >= count_min && view[1][pos[0]] <= count_max)
		return (1);
	else
		return (0);
}
