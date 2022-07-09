/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:28:52 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/09 16:25:53 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

//static int	get_input(int argc, char **argv);

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}


// int	main(int argc, char **argv)
// {
// 	void	*img;
// 	void	*mlx;
	
// 	//get_input(argc, argv);
// 	(void)argc;
// 	(void)argv;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080);
// 	return (0);
// }
/*
static int	get_input(int argc, char **argv)
{
	t_strary	*map;
	t_strary	*copy;

	if (argc != 2)
		return (0);
	map = read_map(argv[1]);
	if (map == NULL)
	{
		write(1, "Erro1\n", 6);
		return (0);
	}
	copy = copy_strs(map);
	if (!(input_check(map) && check_error(copy)))
	{
		write(1, "Erro2\n", 6);
		return (0);
	}
	write(1, "Success\n", 8);	
	free_strs(map, map->size);
	free(map);
	free_strs(copy, copy->size);
	free(copy);
	return (0);
}
*/