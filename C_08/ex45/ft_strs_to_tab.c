/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:05:59 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/22 23:42:23 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include"ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	idx;
	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	        int	idx;
	        int	av_len;

	stock = (t_stock_str *)malloc(sizeof (t_stock_str) * (ac + 1));
	if (stock == NULL)
		return (NULL);
	idx = -1;
	while (++idx < ac)
	{
		av_len = ft_strlen(av[idx]);
		stock[idx].size = av_len;
		stock[idx].str = (char *)malloc(av_len * sizeof (char));
		ft_strcpy(stock[idx].str, av[idx]);
		stock[idx].copy = (char *)malloc(av_len * sizeof (char));
		ft_strcpy(stock[idx].copy, stock[idx].str);
		if (stock[idx].str == NULL || stock[idx].str == NULL)
			return (NULL);
	}
	stock[++idx].size = 0;
	stock[idx].str = 0;
	return (stock);
}
