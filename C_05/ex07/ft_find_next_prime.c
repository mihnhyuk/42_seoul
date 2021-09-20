/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:05:30 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/20 12:07:59 by minhjang         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
