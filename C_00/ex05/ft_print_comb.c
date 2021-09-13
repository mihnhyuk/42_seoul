/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:00:52 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/11 22:42:45 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print_comb(void)
{
	char	*digits;
	 int	idx[3];

	digits = "0123456789,";
	idx[0] = 0;
	while (idx[0] < 8)
	{	
		idx[1] = idx[0] + 1;
		while (idx[1] < 9)
		{
			idx[2] = idx[1] + 1;
			while (idx[2] < 10)
			{
				write(1, digits + idx[0], 1);
				write(1, digits + idx[1], 1);
				write(1, digits + idx[2], 1);
				if (idx[0] != 7)
					write(1, digits + 10, 1);
				idx[2]++;
			}
			idx[1]++;
		}
		idx[0]++;
	}
}
