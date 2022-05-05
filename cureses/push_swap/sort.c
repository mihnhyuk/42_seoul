/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:51:00 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/05 23:29:15 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	pivot_comp(t_stack *a, t_stack *b, t_result *result);
static void	make_a_sorted(t_stack *a, t_stack *b,
				int unsorted_num, t_result *result);
static void	sort_iter(t_stack *a, t_stack *b, t_result *result);

void	sort(t_stack *a, t_stack *b, t_result *result)
{
	if (b->ary == NULL)
		return ;
	pivot_comp(a, b, result);
	sort_iter(a, b, result);
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

static void	sort_iter(t_stack *a, t_stack *b, t_result *result)
{
	while (b->top != -1)
	{
		make_a_sorted(a, b, pivot_comp(b, a, result), result);
	}
}

static void	make_a_sorted(t_stack *a, t_stack *b,
			int unsorted_num, t_result *result)
{
	int	idx;
	int	b_len;

	idx = 0;
	b_len = b->top + 1;
	while (idx < unsorted_num)
	{
		pb(a, b, result);
		idx++;
	}
	idx = 0;
	while (idx < b_len)
	{
		rrb(b, result);
		pa(a, b, result);
		idx++;
	}
}
