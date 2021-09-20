/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:49:15 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/20 21:36:51 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	iter;
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	iter = 0;
	result = 1;
	while (iter < power)
	{
		result *= nb;
		iter++;
	}
	return (result);
}

int	ft_sqrt(int nb)
{
	long long int	iter;
	long long int	pow_iter;

	iter = 1;
	pow_iter = 1;
	while (pow_iter < (long long)nb)
	{
		iter++;
		pow_iter = ft_iterative_power(iter, 2);
	}
	if (pow_iter == (long long int)nb)
		return ((int)iter);
	else
		return (0);
}
