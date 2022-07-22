/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:15:14 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/22 18:22:42 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_object(t_strary *map, t_vars *vars);

void	draw_map(t_strary *map)
{
	t_vars	vars;
	t_imgs	imgs;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1000, "Hello world!");
	map->movements = 0;
	vars.map = map;
	get_asset(&vars, &imgs);
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
				img_put(vars, idx[1], idx[0], vars->img->wall);
			else if (map->ary[idx[0]][idx[1]] == '0')
				draw_empty(vars, idx[1], idx[0]);
			else if (map->ary[idx[0]][idx[1]] == 'C')
				img_put(vars, idx[1], idx[0], vars->img->collect);
			else if (map->ary[idx[0]][idx[1]] == 'E')
				img_put(vars, idx[1], idx[0], vars->img->exit);
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
	img_put(vars, x, y, vars->img->player);
}

void	draw_empty(t_vars *vars, int x, int y)
{
	if (vars->map->ary[y][x] == 'E')
		img_put(vars, x, y, vars->img->exit);
	else
		img_put(vars, x, y, vars->img->floor);
}

void	img_put(t_vars *vars, int x, int y, void *img)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x * PIX, y * PIX);
}
