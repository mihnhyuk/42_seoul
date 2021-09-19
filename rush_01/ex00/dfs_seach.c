/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_seach.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:07:06 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/18 20:40:20 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

extern int g_n;

int	call_next(int *pos, int **view, int **building);
int	dfs_search(int *pos, int **view, int **building);
int	possible(int x, int y, int **view, int **building);

int	call_next(int *pos, int **view, int **building)
{
	int	height;
	int cur_pos[2];
	
	if (pos[1] == -1)
		height = g_n;
	else
		height = building[pos[0]][pos[1]];
	cur_pos[0] = 0;	
	
	if(pos[1] < g_n - 1)
		cur_pos[1] = pos[1] + 1;
	else
	{
		cur_pos[1] = 0;
		if (--height == 0)
			return (1);
	}
	while (cur_pos[0] < g_n)
	{
		if (building[cur_pos[0]][cur_pos[1]] == 0)
		{
			building[cur_pos[0]][cur_pos[1]] = height;
			if(dfs_search(cur_pos, view, building))
				return (1);
		}
		cur_pos[0]++;
	}
	return (0);
}

int dfs_search(int *pos, int **view, int **building)
{
	if(pos[1] != -1)
	{
		if(!possible(pos[0], pos[1], view, building))
		{
			building[pos[0]][pos[1]] = 0;
			return (0);
		}
	}
	if(call_next(pos, view, building))
		return(1);
	else
	{
		building[pos[0]][pos[1]] = 0;
		return (0);
	}
}



