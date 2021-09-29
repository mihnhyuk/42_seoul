/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 08:52:38 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/22 09:15:28 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*new_ary;
	int	idx;

	if (min >= max)
		return (NULL);
	new_ary = (int *)malloc((max - min) * (sizeof (int)));
	if (new_ary == NULL)
		return (NULL);
	idx = 0;
	while (idx < max - min)
	{
		new_ary[idx] = min + idx;
		idx++;
	}
	return (new_ary);
}
