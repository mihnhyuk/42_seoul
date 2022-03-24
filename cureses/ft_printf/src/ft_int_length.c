/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:45:29 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/25 03:49:03 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_int_length(int n, int base)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n + 1 > base)
	{
		length++;
		n /= base;
	}
	length++;
	return (length);
}

int	ft_unsigned_int_length(unsigned int n, unsigned int base)
{
	int	length;

	length = 0;
	while (n + 1 > base)
	{
		length++;
		n /= base;
	}
	length++;
	return (length);
}
