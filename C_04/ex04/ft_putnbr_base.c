/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:59:09 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/22 12:45:31 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	check_base(char *base)
{
	int	ascii[260];
	int	idx;
	int	tmp;
	
	idx = 0;
	while (idx < 260)
	{
		ascii[idx] = 1;
		idx++;
	}
	idx = 0;
	while (base[idx])
	{
		tmp = base[idx];
		if (ascii[tmp])
			ascii[tmp] = 0;
		else
			return (0);
		if (base[idx] == '+' || base[idx] == '-')
			return (0);
		idx++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	        char	ary[15];
	         int	idx;
	unsigned int	to_p;

	len = ft_strlen(base);
	if (len <= 1 || (!check_base(base)))
		return ;
	idx = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		to_p = (unsigned int)(nbr * (-1));
	}
	else
		to_p = (unsigned int)nbr;
	idx = 0;
	while (to_p + 1 > len)
	{
		ary[idx++] = *(base + (to_p % len));
		to_p /= len;
	}
	ary[idx] = *(base + (to_p % len));
	while (idx >= 0)
		write(1, &ary[idx--], 1);
}
