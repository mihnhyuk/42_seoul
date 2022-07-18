/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:36:36 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/17 10:25:58 by minhjang         ###   ########.fr       */
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

// int	collect(t_vars *vars, int px, int py)
// {
// 	if (vars->map->)
// }