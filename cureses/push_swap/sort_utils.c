/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:10:49 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/03 21:27:44 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_aligned(t_stack *s, int range)
{
	int	max;
	int	idx;

	if (s->top < 1)
		return (1);
	idx = s->top;
	max = peek(s);
	while (idx > -1 && range > 0)
	{
		if (s->ary[idx] >= max)
			max = s->ary[idx];
		else
			return (0);
		idx--;
		range--;
	}
	return (1);
}
