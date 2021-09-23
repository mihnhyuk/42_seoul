/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:49:15 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/21 17:00:34 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	iter;
	int	pow_iter;

	iter = 1;
	pow_iter = 1;
	while (pow_iter < nb && iter <= 46340 )
	{
		iter++;
		pow_iter = iter * iter;
	}
	if (pow_iter == nb)
		return (iter);
	else
		return (0);
}
