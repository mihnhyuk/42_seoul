/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:36:36 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/22 18:29:27 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		end_game(vars);
	else if (keycode == UP)
		up(vars);
	else if (keycode == DOWN)
		down(vars);
	else if (keycode == RIGHT)
		right(vars);
	else if (keycode == LEFT)
		left(vars);
	return (0);
}

int	map_name_check(char *arg, t_strary **map)
{
	int	idx;

	*map = read_map(arg);
	if (*map == NULL)
	{
		write(1, "Error\nCan't fint map\n", 21);
		return (0);
	}
	idx = 0;
	while (arg[idx])
		idx++;
	if (arg[idx - 1] == 'r' && arg[idx - 2] == 'e'
		&& arg[idx - 3] == 'b' && arg[idx - 4] == '.')
		return (1);
	else
	{
		write(1, "Error\nMap name must end with .ber\n", 34);
		return (0);
	}
}

int	map_size_check(t_strary *map)
{
	if (map->size > 31 || map->width > 60)
	{
		write(1, "Error\nMap is too big\n", 21);
		return (0);
	}
	return (1);
}

int	line_too_long(t_strary *map, int w, int h, int *ecp)
{
	return (cw(map, w - 1, h, ecp) && cw(map, w - 1, h + 1, ecp)
		&& cw(map, w, h + 1, ecp) && cw(map, w + 1, h + 1, ecp)
		&& cw(map, w + 1, h, ecp) && cw(map, w + 1, h - 1, ecp)
		&& cw(map, w, h - 1, ecp) && cw(map, w - 1, h - 1, ecp));
}
