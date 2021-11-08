/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:38:11 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/23 10:50:22 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"
#include <stdio.h>
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

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
