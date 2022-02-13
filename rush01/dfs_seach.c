/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_seach.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:07:06 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/19 15:59:27 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int		call_next(int n, int *pos, int **view, int **building);
int		dfs_search(int n, int *pos, int **view, int **building);
int		possible(int n, int *pos, int **view, int **building);
void	set_height(int n, int *pos, int *height, int **building);

int	call_next(int n, int *pos, int **view, int **building)
{
	int	height;
	int	cur_pos[2];

	set_height(n, pos, &height, building);
	cur_pos[0] = -1;
	if (pos[1] < n - 1)
		cur_pos[1] = pos[1] + 1;
	else
	{
		cur_pos[1] = 0;
		if (--height == 0)
			return (1);
	}
	while (++cur_pos[0] < n)
	{
		if (building[cur_pos[0]][cur_pos[1]] == 0)
		{
			building[cur_pos[0]][cur_pos[1]] = height;
			if (dfs_search(n, cur_pos, view, building))
				return (1);
		}
	}
	return (0);
}

void	set_height(int n, int *pos, int *height, int **building)
{
	if (pos[1] == -1)
		*height = n;
	else
		*height = building[pos[0]][pos[1]];
}

int	dfs_search(int n, int *pos, int **view, int **building)
{
	if (pos[1] != -1)
	{
		if (!possible(n, pos, view, building))
		{
			building[pos[0]][pos[1]] = 0;
			return (0);
		}
	}
	if (call_next(n, pos, view, building))
		return (1);
	else
	{
		building[pos[0]][pos[1]] = 0;
		return (0);
	}
}
