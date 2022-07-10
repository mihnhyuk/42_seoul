/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:15:14 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/10 17:11:11 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		idx;

	idx = 0;
	while (idx < PIX)
	{
		dst = data->addr + (idx * y * data->line_length + idx * x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		idx++;
	}
}

void	draw_map(t_strary *map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		idx[3];

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 680, "Hello world!");
	img.img = mlx_new_image(mlx, 1080, 680);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	idx[0] = 0;
	while (idx[0] < map->size)
	{
		idx[1] = 0;
		while (idx[1] < map->width)
		{
			my_mlx_pixel_put(&img, idx[0], idx[1], 0x00FF0000);
			idx[1]++;
		}
		idx[0]++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
   