/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:28:52 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/18 16:35:08 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

static t_strary	*get_input(int argc, char **argv);
static void		get_coin(t_strary *map);
static void		init_coll_pos(t_strary *map);

int	main(int argc, char **argv)
{
	t_strary	*map;

	map = get_input(argc, argv);
	if (map == NULL)
		return (0);
	draw_map(map);
	system("leaks so_long");
}

static t_strary	*get_input(int argc, char **argv)
{
	t_strary	*map;
	t_strary	*copy;
	(void)argv;
	if (argc != 2)
		return (0);
	map = read_map(argv[1]);
	if (map == NULL)
	{
		write(1, "Error1\n", 7);
		return (NULL);
	}
	copy = copy_strs(map);
	if (!(input_check(map) && check_error(copy)))
	{
		write(1, "Error2\n", 7);
		free_strs(map, map->size);
		free(map);
		free_strs(copy, copy->size);
		free(copy);
		return (NULL);
	}
	free_strs(copy, copy->size);
	free(copy);
	get_coin(map);
	return (map);
}

static void	get_coin(t_strary *map)
{
	int	idx[2];

	init_coll_pos(map);
	map->coin_num = 0;
	idx[0] = 0;
	while (idx[0] < map->size)
	{
		idx[1] = 0;
		while (idx[1] < map->width)
		{
			map->coll_pos[idx[0]][idx[1]] = 0;
			if (map->ary[idx[0]][idx[1]] == 'C')
			{
				map->coin_num += 1;
				map->coll_pos[idx[0]][idx[1]] = 1;
			}

			idx[1] += 1;
		}
		idx[0] += 1;
	}
}

static void	init_coll_pos(t_strary *map)
{
	int	idx;

	map->coll_pos = (int **)malloc(sizeof(int *) * map->size);
	if (map->coll_pos == NULL)
		free_strs(map, map->size);
	idx = 0;
	while (idx < map->size)
	{
		map->coll_pos[idx] = (int *)malloc(sizeof(int) * map->width);
		if (map->coll_pos[idx] == NULL)
		{
			free_coll(map, idx);
			free_strs(map, map->size);
			return ;
		}
		idx++;
	}
}