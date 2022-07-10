/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:28:52 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/10 17:06:30 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

static t_strary	*get_input(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_strary	*map;

	map = get_input(argc, argv);
	draw_map(map);
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
	return (map);
}