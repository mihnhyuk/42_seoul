/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:50:10 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/20 15:00:47 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	iter;
	int	str_iter;

	iter = argc;
	while (--iter > 0)
	{
		str_iter = 0;
		while (argv[iter][str_iter])
		{
			write(1, &argv[iter][str_iter], 1);
			str_iter++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
