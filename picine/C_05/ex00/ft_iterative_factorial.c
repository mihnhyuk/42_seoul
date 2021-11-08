/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:17:08 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/20 11:25:27 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	facto;
	int	idx;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	facto = 1;
	idx = 1;
	while (idx <= nb)
	{
		facto *= idx;
		idx++;
	}
	return (facto);
}
