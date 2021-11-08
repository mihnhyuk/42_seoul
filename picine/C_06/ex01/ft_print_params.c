/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:45:12 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/20 14:49:39 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	iter;
	int	iter2;

	iter = 1;
	while (iter < argc)
	{
		iter2 = 0;
		while (argv[iter][iter2])
			write(1, &argv[iter][iter2++], 1);
		write(1, "\n", 1);
		iter++;
	}
}
