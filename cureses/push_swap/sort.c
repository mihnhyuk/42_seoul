/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:54:59 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/04 20:53:46 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	a_to_b(t_stack *a, t_stack *b, t_result *r, int range);
static void	b_to_a(t_stack *a, t_stack *b, t_result *r, int range);
static int	a_to_b_cond(t_stack *a, t_stack *b, t_result *r, int pivot);
static int	b_to_a_cond(t_stack *a, t_stack *b, t_result *r, int pivot);

void	sort(t_stack *a, t_stack *b, t_result *r)
{
	if (is_aligned(a, a->top + 1))
		return ;
	else if (a->top == 1)
	{
		sa(a, r);
		return ;
	}
	else if (a-> top == 2)
	{
		three(a, r);
		return ;
	}
	a_to_b(a, b, r, a->top + 1);
}

static void	a_to_b(t_stack *a, t_stack *b, t_result *r, int range)
{
	int	pivot;
	int	idx;
	int	r_p_num[3];

	r_p_num[2] = a->top + 1;
	if (is_aligned(a, range))
		return ;
	if (atob_opt(a, r, range))
		return ;
	idx = -1;
	r_p_num[0] = 0;
	r_p_num[1] = 0;
	pivot = find_pivot(a, range);
	while (++idx < range)
	{
		if (a_to_b_cond(a, b, r, pivot))
			(r_p_num[0])++;
		else
			(r_p_num[1])++;
	}
	idx = -1;
	while (++idx < r_p_num[0] && range != r_p_num[2])
		rra(a, r);
	a_to_b(a, b, r, r_p_num[0]);
	b_to_a(a, b, r, r_p_num[1]);
}

static void	b_to_a(t_stack *a, t_stack *b, t_result *r, int range)
{
	int	pivot;
	int	idx;
	int	r_p_num[3];

	r_p_num[2] = b->top + 1;
	if (range == 1 || is_reversed(b, range))
		return (btoa_opt(a, b, r, range));
	idx = -1;
	r_p_num[0] = 0;
	r_p_num[1] = 0;
	pivot = find_pivot(b, range);
	while (++idx < range)
	{
		if (b_to_a_cond(a, b, r, pivot))
			(r_p_num[0])++;
		else
			(r_p_num[1])++;
	}
	idx = -1;
	while (++idx < r_p_num[0] && range != r_p_num[2])
		rrb(b, r);
	a_to_b(a, b, r, r_p_num[1]);
	b_to_a(a, b, r, r_p_num[0]);
}

static int	a_to_b_cond(t_stack *a, t_stack *b, t_result *r, int pivot)
{
	if (peek(a) >= pivot)
	{
		ra(a, r);
		return (1);
	}
	else
	{
		pb(a, b, r);
		return (0);
	}
}

static int	b_to_a_cond(t_stack *a, t_stack *b, t_result *r, int pivot)
{
	if (peek(b) < pivot)
	{
		rb(b, r);
		return (1);
	}
	else
	{
		pa(a, b, r);
		return (0);
	}
}
