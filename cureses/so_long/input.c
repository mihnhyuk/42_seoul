/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:25:51 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/22 18:28:24 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>

static int	line_check(const char *str);
static int	cw(t_strary *map, int w, int h, int *ecp);

t_strary	*read_map(const char *map_name)
{
	int			fd;
	char		*line;
	t_strary	*map;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (t_strary *)malloc(sizeof(t_strary));
	if (map == NULL)
		return (NULL);
	if (init_strs(map, 10) == NULL)
		return (NULL);
	line = get_next_line(fd);
	map->width = line_check(line);
	while (line != NULL)
	{
		if (push_string(map, line) == NULL)
		{
			free(map);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int	input_check(t_strary *map)
{
	int	height;
	int	width;

	height = 0;
	width = line_check(map->ary[height]);
	if (width == 0)
		return (0);
	while (++height < map->size)
	{
		if (width != line_check(map->ary[height]))
		{
			return (0);
		}
	}
	return (1);
}

int	check_error(t_strary *map)
{
	int	w;
	int	h;
	int	ecp[3];

	h = -1;
	ecp[0] = 0;
	ecp[1] = 0;
	ecp[2] = 0;
	while (++h < map->size)
	{
		w = -1;
		while (++w < map->width)
		{
			if (map->ary[h][w] != '1')
			{
				if (!cw(map, w, h, ecp))
					return (0);
			}
		}
	}
	if (!(ecp[0] && ecp[1] && ecp[2]))
		return (0);
	return (1);
}

static int	cw(t_strary *map, int w, int h, int *ecp)
{
	if (w < 0 || h < 0 || w >= map->width || h >= map->size
		|| (ecp[2] == 1 && map->ary[h][w] == 'P'))
		return (0);
	if (map->ary[h][w] == '1')
		return (1);
	else if (map->ary[h][w] == 'E')
	{
		ecp[0] = 1;
		map->ary[h][w] = '1';
	}
	else if (map->ary[h][w] == 'C')
	{
		ecp[1] = 1;
		map->ary[h][w] = '1';
	}
	else if (map->ary[h][w] == 'P')
	{
		ecp[2] = 1;
		map->ary[h][w] = '1';
	}
	else if (map->ary[h][w] == '0')
		map->ary[h][w] = '1';
	return (line_too_long(map, w, h, ecp));
}

static int	line_check(const char *str)
{
	int	iter;

	iter = 0;
	if (str == NULL)
		return (0);
	while (str[iter] && str[iter] != '\n')
	{
		if (!(str[iter] == '0' || str[iter] == '1' || str[iter] == 'C'
				|| str[iter] == 'E' || str[iter] == 'P'))
		{
			return (0);
		}
		iter++;
	}
	return (iter);
}
