/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:24:32 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/18 19:27:57 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putnbr(int nb)
{
	        char	ascii[11];
	         int	idx;
	unsigned int	to_p;

	idx = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		to_p = (unsigned int)(nb * (-1));
	}	
	else
		to_p = (unsigned int)nb;
	while (nb > 9)
	{
		ascii[idx++] = (to_p % 10) + '0';
		to_p /= 10;
	}
	ascii[idx] = (to_p % 10) + '0';
	while (idx >= 0)
	{
		write(1, &ascii[idx--], 1);
	}
}
