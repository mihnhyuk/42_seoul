/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 23:24:32 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/11 23:57:03 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putnbr(int nb)
{
	      char	ascii[11];
	       int	idx;
	const char	sign_mark = '-';
	const char	*min_int = "-2147483648";

	idx = 0;
	if (nb == -2147483648)
	{
		write(1, min_int, 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, &sign_mark, 1);
		nb *= -1;
	}	
	while (nb > 0 )
	{
		ascii[idx++] = (nb % 10) + 48;
		nb /= 10;
	}
	while (idx >= 0)
	{
		write(1, &ascii[idx--], 1);
	}
}
