/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:51:00 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/06 02:28:40 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	pivot_comp(t_stack *a, t_stack *b, t_result *result);
static int	merge_sort(t_stack *a, t_stack *b, t_result *result);

void	sort(t_stack *a, t_stack *b, t_result *result)
{
	if (b->ary == NULL)
		return ;
	pivot_comp(a, b, result);
	while (b->top != -1)
	{
		merge_sort(a, b, result);
	}
}

static int	pivot_comp(t_stack *a, t_stack *b, t_result *result)
{
	int	a_length;
	int	max;
	int	counter;

	counter = 0;
	a_length = a->top + 1;
	max = peek(a);
	while (a_length > 0)
	{
		if (max <= peek(a))
			max = peek(a);
		else
		{
			pb(a, b, result);
			a_length--;
			counter++;
			continue ;
		}
			ra(a, result);
		a_length--;
	}
	return (counter);
}

static int	merge_sort(t_stack *a, t_stack *b, t_result *result)
{
	int	b_length;
	int a_length;
	int	min;

	b_length = b->top + 1;
	a_length = a->top + 1;
	min = peek(b);
	while (b_length > 0)
	{
		if (min >= peek(b))
		{
			min = peek(b);
			while (a_length > 0 && a->ary[0] > min)
			{
				rra(a, result);
				a_length--;
			}
			pa(a, b, result);
			b_length--;
		}
		else
		{
			rb(b, result);
			b_length--;
		}
	}
	while (a_length-- > 0)
		rra(a, result);
	return (0);
}
