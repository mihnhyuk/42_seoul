/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:15:14 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/10 18:22:48 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		idx[2];

	idx[0] = 0;
	while (idx[0] < PIX)
	{
		idx[1] = 0;
		while (idx[1] < PIX)
		{
			dst = data->addr + ((y * PIX + idx[1]) * data->line_length + 
					(x * PIX + idx[0]) * (data->bits_per_pixel / 8));
			*(unsigned int*)dst = color;
			idx[1]++;
		}
		idx[0]++;
	}
}

int	close(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	draw_map(t_strary *map)
{
	t_data	img;
	int		idx[3];
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 680, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 680);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	idx[0] = 0;
	while (idx[0] < map->size)
	{
		idx[1] = 0;
		while (idx[1] < map->width)
		{
			if (map->ary[idx[0]][idx[1]] == '1')
				my_mlx_pixel_put(&img, idx[1], idx[0], 0x00FF6699);
			idx[1]++;
		}
		idx[0]++;
	}
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
   