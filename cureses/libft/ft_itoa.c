/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:35:21 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/31 18:33:23 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	num_length(unsigned int n, int sign)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	if (length == 0)
		length++;
	if (sign == -1)
		length++;
	return (length);
}

char	*ft_itoa(int n)
{
	unsigned int	u_n;
	int				sign;
	int				length;
	char			*result;

	u_n = n;
	sign = 1;
	if (n < 0)
	{
		u_n = n * (-1);
		sign = -1;
	}
	length = num_length(u_n, sign);
	result = (char *)malloc(sizeof(char) * length + 1);
	result[length] = 0;
	while (u_n > 9)
	{
		result[--length] = u_n % 10 + '0';
		u_n /= 10;
	}
	result[--length] = u_n % 10 + '0';
	if (sign == -1)
		result[--length] = '-';
	return (result);
}
