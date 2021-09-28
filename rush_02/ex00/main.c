/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeukim <gaeukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:17:25 by gaeukim           #+#    #+#             */
/*   Updated: 2021/09/26 18:27:28 by minhjang         ###   ########.fr       */
/*   Updated: 2021/09/26 17:23:55 by kyuchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	input(char *file_name);

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int	main(int argc, char *argv[])
{
	int	**result;

	if (argc != 2)
	{
		ft_error();
		return (0);
	}
	input(argv[1]);
}
