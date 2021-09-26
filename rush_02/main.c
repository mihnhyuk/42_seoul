/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeukim <gaeukim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:17:25 by gaeukim           #+#    #+#             */
/*   Updated: 2021/09/26 16:03:44 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
