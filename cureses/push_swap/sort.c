/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:54:59 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/03 21:05:10 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void A_to_B(t_stack *a, t_stack *b, t_result *r, int range);
static void B_to_A(t_stack *a, t_stack *b, t_result *r, int range);
static int A_to_B_cond(t_stack *a, t_stack *b, t_result *r, int pivot);
static int B_to_A_cond(t_stack *a, t_stack *b, t_result *r, int pivot);

void	sort(t_stack *a, t_stack *b, t_result *r)
{
	A_to_B(a, b, r, a->top + 1);
}

static void A_to_B(t_stack *a, t_stack *b, t_result *r, int range)
{
	int	pivot;
	int idx;
	int	r_p_num[2];

	if (range <= 1)
		return ;
	idx = -1;
	r_p_num[0] = 0;
	r_p_num[1] = 0;
	pivot = find_pivot(a, range);
	while (++idx < range)
	{
		if (A_to_B_cond(a, b, r, pivot))
			(r_p_num[0])++;
		else
			(r_p_num[1])++;
	}
	idx = -1;
	while (++idx < r_p_num[0])
		rra(a, r);
	A_to_B(a, b, r, r_p_num[0]);
	B_to_A(a, b, r, r_p_num[1]);
}

static void B_to_A(t_stack *a, t_stack *b, t_result *r, int range)
{
	int	pivot;
	int idx;
	int	r_p_num[2];
	
	if (range == 1)
	{
		pa(a, b, r);
		return ;
	}
	idx = -1;
	r_p_num[0] = 0;
	r_p_num[1] = 0;
	pivot = find_pivot(b, range);
	while (++idx < range)
	{
		if (B_to_A_cond(a, b, r, pivot))
			(r_p_num[0])++;
		else
			(r_p_num[1])++;
	}
	idx = -1;
	while (++idx < r_p_num[0])
		rrb(b, r);
	A_to_B(a, b, r, r_p_num[1]);
	B_to_A(a, b, r, r_p_num[0]);
}

static int A_to_B_cond(t_stack *a, t_stack *b, t_result *r, int pivot)
{
	if (peek(a) >= pivot)
	{
		ra(a, r);
		return (1);
	}
	else
	{
		pb(a, b, r);
		return(0);
	}
}

static int B_to_A_cond(t_stack *a, t_stack *b, t_result *r, int pivot)
{
	if (peek(b) < pivot)
	{
		rb(b, r);
		return (1);
	}
	else
	{
		pa(a, b, r);
		return(0);
	}
}