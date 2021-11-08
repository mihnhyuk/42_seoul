/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:19:27 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/22 09:27:53 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	idx;

	if (min >= max)
	{
		(*range) = NULL;
		return (0);
	}
	(*range) = (int *)malloc((max - min) * sizeof (int));
	if (*range == NULL)
		return (-1);
	idx = 0;
	while (idx < max - min)
	{
		(*range)[idx] = min + idx;
		idx++;
	}
	return (max - min);
}
