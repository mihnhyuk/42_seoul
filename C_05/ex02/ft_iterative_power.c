/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:26:07 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/20 11:32:44 by minhjang         ###   ########.fr       */
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
