/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:59:09 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/19 21:16:33 by minhjang         ###   ########.fr       */
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

	idx = 0;
	while (idx < 260)
	{
		ascii[idx] = 1;
		idx++;
	}
	idx = 0;
	while (base[idx])
	{
		if (ascii[base[idx]])
			asc[base[idx]] = 0;
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
	         int	len;
	        char	ary[15];
	         int	idx;
	unsigned int	to_p;

	len = ft_strlen(base);
	if (len < 0 || (!check_base(base)))
		return (0);
	idx = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		to_p = (unsigned int)(nbr * (-1));
	}
	else
		to_p = (unsigned int)nbr;
	idx = 0;
	while (to_p > len - 1)
	{
		ary[idx] = base + (to_p % len);
		idx++;
	}
	ary[idx] = base + (to_p % len);
	while (idx >= 0)
		write(1, &ary[idx], 1);
}
