/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:21:28 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/29 19:21:29 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_putnbr(int nb)
{
	unsigned int	n;
	        char	ary[15];
	         int	idx;

	idx = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = (unsigned int)(nb * (-1));
	}
	else
		n = (unsigned int)nb;
	while (n > 9)
	{
		ary[idx] = (n % 10) + '0';
		n /= 10;
		idx++;
	}
	ary[idx] = n + '0';
	while (idx >= 0)
	{
		write(1, &ary[idx], 1);
		idx--;
	}
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	write(1, str, idx);
}
