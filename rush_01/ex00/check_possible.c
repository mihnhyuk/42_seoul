/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:08:34 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/18 20:29:28 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	int g_n;

int	check_left(int x, int y, int **view, int **building);
int	check_right(int x, int y, int **view, int **building);
int	check_up(int x, int y, int **view, int **building);
int	check_down(int x, int y, int **view, int **building);

int	possible(int x, int y, int **view, int **building)
{
	int	idx;

	idx = 0;
	while (idx < y)
	{
		if ( building[x][idx] == building[x][y])
			return (0);
		idx++;
	}
	if (check_left(x, y, view, building) && check_right(x, y, view, building) 
		&& check_up(x, y, view, building) && check_down(x, y, view, building))
		return(1);
	else
		return(0);

}

int	check_left(int x, int y, int **view, int **building)
{
	int	max;
	int	count_max;
	int	count_min;
	int	idx;

	max = -1;
	count_max = 0;
	count_min = 0;
	idx = 0;
	while (idx < g_n)
	{
		if (max <= building[idx][y])
		{
			count_max++;
			if (max < building[idx][y])
				count_min++;
			max = building[idx][y];
		}
		idx++;
	}
	if (view[2][y] >= count_min && view[2][y] <= count_max)
		return (1);
	else
		return (0);
}
int	check_right(int x, int y, int **view, int **building)
{
	int	max;
	int	count_max;
	int	count_min;
	int	idx;

	max = -1;
	count_max = 0;
	count_min = 0;
	idx = g_n - 1;
	while (idx >= 0)
	{
		if (max <= building[idx][y])
		{
			count_max++;
			if (max < building[idx][y])
				count_min++;
			max = building[idx][y];
		}
		idx--;
	}
	if (view[3][y] >= count_min && view[3][y] <= count_max)
		return (1);
	else
		return (0);
}
int	check_up(int x, int y, int **view, int **building)
{
	int	max;
	int	count_max;
	int	count_min;
	int	idx;

	max = -1;
	count_max = 0;
	count_min = 0;
	idx = 0;
	while (idx < g_n)
	{
		if (max <= building[x][idx])
		{
			count_max++;
			if (max < building[x][idx])
				count_min++;
			max = building[x][idx];
		}
		idx++;
	}
	if (view[0][x] >= count_min && view[0][x] <= count_max)
		return (1);
	else
		return (0);
}
int	check_down(int x, int y, int **view, int **building)
{
	int	max;
	int	count_max;
	int	count_min;
	int	idx;

	max = -1;
	count_max = 0;
	count_min = 0;
	idx = g_n - 1;
	while (idx >= 0)
	{
		if (max <= building[x][idx])
		{
			count_max++;
			if (max < building[x][idx])
				count_min++;
			max = building[x][idx];
		}
		idx--;
	}
	if (view[1][x] >= count_min && view[1][x] <= count_max)
		return (1);
	else
		return (0);
}

