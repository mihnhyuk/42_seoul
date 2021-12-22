/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:35:21 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/22 15:35:23 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_itoa(int n)
{
	unsigned int	u_n;
	int				sign;
	int				idx;
	char			*result;
	char			tmp[20];

	u_n = n;
	if (n < 0)
		u_n = n * (-1);
	sign = (int)u_n / n;
	idx = 0;
	while (u_n > 0)
	{
		tmp[idx++] = u_n % 10;
		u_n /= 10;
	}
	if (sign == -1)
		tmp[idx++] = '-';
	result = (char *)malloc(sizeof(char) * idx);
	sign = 0;
	while (idx >= 0)
		result[sign++] = tmp[idx--];
	return (result);
}
