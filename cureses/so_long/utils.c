/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:23:01 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/18 16:44:04 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_coll(t_strary *map, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		free(map->coll_pos[idx]);
		idx++;
	}
	free(map->coll_pos);
	return (NULL);
}

void	check_event(t_vars *vars, int x, int y)
{
	if (vars->map->coll_pos[y][x] == 1)
	{
		vars->map->coin_num -= 1;
		vars->map->coll_pos[y][x] = 0;
	}
	else if (vars->map->ary[y][x] == 'E' && vars->map->coin_num == 0)
	{
		end_game(vars);
	}
}