/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:15:14 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/18 16:30:08 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_object(t_strary *map, t_vars *vars);
void	draw_player(t_vars *vars, int x, int y);
void	draw_empty(t_vars *vars, int x, int y);

void	draw_map(t_strary *map)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 680, "Hello world!");
	map->movements = 0;
	vars.map = map;
	draw_object(map, &vars);
	mlx_hook(vars.win, 17, 1L << 2, &end_game, &vars);
	mlx_key_hook(vars.win, &key_hook, &vars);
	mlx_loop(vars.mlx);
}

static void	draw_object(t_strary *map, t_vars *vars)
{
	int	idx[2];

	idx[0] = 0;
	while (idx[0] < map->size)
	{
		idx[1] = 0;
		while (idx[1] < map->width)
		{
			if (map->ary[idx[0]][idx[1]] == '1')
				pixel_put(vars, idx[1], idx[0], WALLC);
			else if (map->ary[idx[0]][idx[1]] == '0')
				draw_empty(vars, idx[1], idx[0]);
			else if (map->ary[idx[0]][idx[1]] == 'C')
				pixel_put(vars, idx[1], idx[0], COLLECTALBEC);
			else if (map->ary[idx[0]][idx[1]] == 'E')
				pixel_put(vars, idx[1], idx[0], EXITC);
			else if (map->ary[idx[0]][idx[1]] == 'P')
				draw_player(vars, idx[1], idx[0]);
			idx[1]++;
		}
		idx[0]++;
	}
}

void	draw_player(t_vars *vars, int x, int y)
{
	vars->map->x = x;
	vars->map->y = y;
	
	pixel_put(vars, x, y, PLAYERC);
}

void	draw_empty(t_vars *vars, int x, int y)
{
	if (vars->map->ary[y][x] == 'E')
		pixel_put(vars, x, y, EXITC);
	else
		pixel_put(vars, x, y, EMPTYC);
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
			mlx_pixel_put(vars->mlx, vars->win, x * PIX + idx[1], y * PIX + idx[0], color);
			idx[1]++;
		}
		idx[0]++;
	}
}
