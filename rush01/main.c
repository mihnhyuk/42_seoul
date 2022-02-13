/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:36:06 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/19 18:59:21 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		dfs_search(int n, int *pos, int **view, int **building);
int		input(int *n, int ***view, int ***building, char *str);
void	output(int n, int ***view, int ***building);
void	free_all(int n, int ***view, int ***building);

int	main(int argc, char *argv[])
{
	int	**building;
	int	**view;
	int	idx[2];
	int	board_size;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (input(&board_size, &view, &building, argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	idx[1] = -1;
	if (dfs_search(board_size, idx, view, building))
		output(board_size, &view, &building);
	else
	{
		write(1, "Error\n", 6);
		free_all(board_size, &view, &building);
	}
}
