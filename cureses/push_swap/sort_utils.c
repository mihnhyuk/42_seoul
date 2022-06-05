/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:10:49 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/04 20:53:24 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	three(t_stack *a, t_result *r)
{
	if (a->ary[0] > a->ary[1] && a->ary[0] > a->ary[2])
		sa(a, r);
	else if (a->ary[1] > a->ary[2])
	{
		if (a->ary[2] > a->ary[0])
			rra(a, r);
		else
		{
			sa(a, r);
			ra(a, r);
		}		
	}
	else
	{
		ra(a, r);
		if (a->ary[2] > a->ary[1])
			sa(a, r);
	}
}

int	is_reversed(t_stack *b, int range)
{
	int	idx;
	int	min;

	idx = b->top;
	min = peek(b);
	while (--range > 0)
	{
		if (min > b->ary[--idx])
			min = b->ary[idx];
		else
			return (0);
	}
	return (1);
}

void	btoa_opt(t_stack *a, t_stack *b, t_result *r, int range)
{
	int	idx;

	idx = -1;
	if (is_reversed(b, range))
	{
		while (++idx < range)
			pa(a, b, r);
	}
	else if (range == 2)
	{
		sb(b, r);
		pa(a, b, r);
		pa(a, b, r);
	}
}

int	atob_opt(t_stack *a, t_result *r, int range)
{
	if (range == 2)
	{
		sa(a, r);
		return (1);
	}
	else if (a->top == 2)
	{
		if (!is_aligned(a, range))
			three(a, r);
		return (1);
	}
	else if (range == 3)
	{
		if (a->ary[a->top - 2] > peek(a)
			&& a->ary[a->top - 2] > a->ary[a->top - 1])
		{
			sa(a, r);
			return (1);
		}
	}
	return (0);
}
