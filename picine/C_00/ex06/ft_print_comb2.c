/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:52:04 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/11 23:20:11 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print_comb2(void)
{
	const char	*digits_comma = "0123456789, ";
	       int	idx[2];

	idx[0] = 0;
	while (idx[0] < 99)
	{
		idx[1] = idx[0] + 1;
		while (idx[1] < 100)
		{
			write(1, digits_comma + (idx[0] / 10), 1);
			write(1, digits_comma + (idx[0] % 10), 1);
			write(1, digits_comma + 11, 1);
			write(1, digits_comma + (idx[1] / 10), 1);
			write(1, digits_comma + (idx[1] % 10), 1);
			if (idx[0] != 98)
				write(1, digits_comma + 10, 2);
			idx[1]++;
		}
		idx[0]++;
	}
}
