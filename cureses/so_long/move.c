/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:56:51 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/24 18:15:11 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_vars *vars)
{
	int	cx;
	int	cy;

	cx = vars->map->x;
	cy = vars->map->y;
	if (cx > 0 && vars->map->ary[cy][cx - 1] != '1')
	{
		pixel_put(vars, cx, cy, 0x00000000);
		draw_empty(vars, cx, cy);
		draw_player(vars, cx - 1, cy);
		vars->map->x = cx - 1;
		vars->map->movements += 1;
		ft_putnbr_fd(vars->map->movements, 1);
		write(1, "\n", 1);
		check_event(vars, cx - 1, cy);
	}
}

void	right(t_vars *vars)
{
	int	cx;
	int	cy;

	cx = vars->map->x;
	cy = vars->map->y;
	if (cx < vars->map->width - 1 && vars->map->ary[cy][cx + 1] != '1')
	{
		pixel_put(vars, cx, cy, 0x00000000);
		draw_empty(vars, cx, cy);
		draw_player(vars, cx + 1, cy);
		vars->map->x = cx + 1;
		vars->map->movements += 1;
		ft_putnbr_fd(vars->map->movements, 1);
		write(1, "\n", 1);
		check_event(vars, cx + 1, cy);
	}
}

void	up(t_vars *vars)
{
	int	cx;
	int	cy;

	cx = vars->map->x;
	cy = vars->map->y;
	if (cy > 0 && vars->map->ary[cy - 1][cx] != '1')
	{
		pixel_put(vars, cx, cy, 0x00000000);
		draw_empty(vars, cx, cy);
		draw_player(vars, cx, cy - 1);
		vars->map->y = cy - 1;
		vars->map->movements += 1;
		ft_putnbr_fd(vars->map->movements, 1);
		write(1, "\n", 1);
		check_event(vars, cx, cy - 1);
	}
}

void	down(t_vars *vars)
{
	int	cx;
	int	cy;

	cx = vars->map->x;
	cy = vars->map->y;
	if (cx > 0 && vars->map->ary[cy + 1][cx] != '1')
	{
		pixel_put(vars, cx, cy, 0x00000000);
		draw_empty(vars, cx, cy);
		draw_player(vars, cx, cy + 1);
		vars->map->y = cy + 1;
		vars->map->movements += 1;
		ft_putnbr_fd(vars->map->movements, 1);
		write(1, "\n", 1);
		check_event(vars, cx, cy + 1);
	}
}

int	end_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_strs(vars->map, vars->map->size);
	free_coll(vars->map, vars->map->size);
	free(vars->map);
	exit(0);
}
