/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:56:27 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/20 12:04:52 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	iter;

	if (nb == 2)
		return (1);
	if (nb <= 1)
		return (0);
	iter = 2;
	while (iter <= nb / 2)
	{
		if (nb % iter == 0)
			return (0);
		iter++;
	}
	return (1);
}
