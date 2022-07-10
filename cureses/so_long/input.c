/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:25:51 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/10 16:46:12 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "str_ary.h"
#include <fcntl.h>

static int	line_check(const char *str);
static int			cw(t_strary *map, int w, int h, int *ECP);

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
	int	ECP[3];

	h = -1;
	ECP[0] = 0;
	ECP[1] = 0;
	ECP[2] = 0;
	while (++h < map->size)
	{
		w = -1;
		while (++w < map->width)
		{
			if (map->ary[h][w] != '1')
			{
				if (!cw(map, w, h, ECP))
					return (0);
			}
		}
	}
	if (!(ECP[0] && ECP[1] && ECP[2]))
		return (0);
	return (1);
}

static int	cw(t_strary *map, int w, int h, int *ECP)
{
	if (w < 0 || h < 0 || w >= map->width || h >= map->size
			|| (ECP[2] == 1 && map->ary[h][w] == 'P'))
		return (0);
	if (map->ary[h][w] == '1')
		return (1);
	else if (map->ary[h][w] == 'E')
	{
		ECP[0] = 1;
		map->ary[h][w] = '1';
	}
	else if (map->ary[h][w] == 'C')
	{
		ECP[1] = 1;
		map->ary[h][w] = '1';
	}
	else if (map->ary[h][w] == 'P')
	{
		ECP[2] = 1;
		map->ary[h][w] = '1';
	}
	else if (map->ary[h][w] == '0')
		map->ary[h][w] = '1';
	return (cw(map, w - 1, h, ECP) && cw(map, w - 1, h + 1, ECP) && cw(map, w, h + 1, ECP)
			&& cw(map, w + 1, h + 1, ECP) && cw(map, w + 1, h, ECP) && cw(map, w + 1, h - 1, ECP)
			&& cw(map, w, h - 1, ECP) && cw(map, w - 1 , h - 1, ECP));
}

static int	line_check(const char *str)
{
	int	iter;

	iter = 0;
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
