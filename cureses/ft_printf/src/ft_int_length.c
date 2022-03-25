/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:45:29 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/25 13:20:34 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_int_length(int nb, unsigned int base)
{
	int				length;
	unsigned int	n;

	length = 0;
	n = nb;
	if (nb < 0)
	{
		length++;
		n = nb * (-1);
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
