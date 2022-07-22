/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:23:01 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/22 18:33:53 by minhjang         ###   ########.fr       */
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

void	get_asset(t_vars *var, t_imgs *imgs)
{
	int	width;
	int	height;

	var->img = imgs;
	width = PIX;
	height = PIX;
	imgs->floor = mlx_xpm_file_to_image(var->mlx,
			"./img/floor.xpm", &width, &height);
	imgs->exit = mlx_xpm_file_to_image(var->mlx,
			"./img/exit.xpm", &width, &height);
	imgs->collect = mlx_xpm_file_to_image(var->mlx,
			"./img/collect.xpm", &width, &height);
	imgs->player = mlx_xpm_file_to_image(var->mlx,
			"./img/player.xpm", &width, &height);
	imgs->wall = mlx_xpm_file_to_image(var->mlx,
			"./img/wall.xpm", &width, &height);
}

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	int		idx[2];

	idx[0] = 0;
	while (idx[0] < PIX)
	{
		idx[1] = 0;
		while (idx[1] < PIX)
		{
			mlx_pixel_put(vars->mlx, vars->win,
				x * PIX + idx[1], y * PIX + idx[0], color);
			idx[1]++;
		}
		idx[0]++;
	}
}

void	*print_err(t_strary *map, t_strary *copy)
{
	write(1, "Error\nMap Error", 15);
	free_strs(map, map->size);
	free(map);
	free_strs(copy, copy->size);
	free(copy);
	return (NULL);
}
