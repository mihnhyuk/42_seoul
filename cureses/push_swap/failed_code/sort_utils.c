/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:17:49 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/03 04:27:11 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int		is_aligned(t_stack *s, t_stack *ali);
void	sort_merge(t_stack *a, t_stack *b, t_result *result, t_stack *ali);

int is_aligned(t_stack *s, t_stack *ali)
{
	int max;
	int min;
	int	idx;

	idx = 0;
	if (s->top < 0)
		return (0);
	max = s->ary[0];
	min = s->ary[0];
	ali->ary[0] = 1;
	ali->ary[1] = 1;
	while (idx++ < s->top)
	{
		if (s->ary[idx] >= max)
			max = s->ary[idx];
		else
			ali->ary[0]++;
		if (s->ary[idx] <= min)
			min = s->ary[idx];
		else
			ali->ary[1]++;
	}
	return (ali->ary[1]);
}

void	sort_merge(t_stack *a, t_stack *b, t_result *result, t_stack *ali)
{
	int idx;
	int	idx2;

	idx = b->top;
	idx2 = 0;
	while (idx >= 0 && idx2 <= ali->top)
	{
		if (idx == ali->ary[idx2])
		{
			insert(a, b, result, search_insert_position(a, b));
			idx2++;
		}
		else
			rb(b, result);
		idx--;
	}
}