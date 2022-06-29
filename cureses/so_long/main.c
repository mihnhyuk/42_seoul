/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:28:52 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/29 16:32:10 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
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
}