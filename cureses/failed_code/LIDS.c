/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIDS.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:11:31 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/03 03:20:41 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

static void	LIDS_max(t_stack *max, t_stack *b, t_stack *idx);
static void	LIDS_min(t_stack *min, t_stack *b, t_stack *idx);
static void	find_LIDS(t_stack *ali, t_stack *idx, int range);
static void	init_idx(t_stack *idx1, t_stack *idx2, t_stack *b);

int	LIDS(t_stack *b, t_stack *ali)
{
	t_stack	max;
	t_stack min;
	t_stack	idx[2];
	int		d;
	
	init_idx(idx, idx + 1, b);
	init_stack(&max);
	init_stack(&min);
	
	LIDS_max(&max, b, idx);
	LIDS_min(&min, b, idx + 1);
	if (max.top > min.top){
		find_LIDS(ali, idx, max.top);
		//printf("max\n");
	}else{
		find_LIDS(ali, idx + 1, max.top);
		//printf("min\n");
	}d = max.top > min.top ? max.top : min.top;
	free(max.ary);
	free(min.ary);
	free(idx[0].ary);
	free(idx[1].ary);
	return (d);
}

static void	LIDS_max(t_stack *max, t_stack *b, t_stack *idx)
{
	int	i;
	int i2;

	push(max, b->ary[0]);
	push(idx, 0);
	i = 0;
	while (++(i) <= b->top)
	{
		if (peek(max) <= b->ary[i])
		{
			push(max, b->ary[i]);
			push(idx, max->top);
		}
		else
		{
			i2 = max->top;
			while (i2 > 0 && max->ary[i2 - 1] > b->ary[i])
				i2--;
			max->ary[i2] = b->ary[i];
			push(idx, i2);
		}
	}
}

static void	LIDS_min(t_stack *min, t_stack *b, t_stack *idx)
{
	int	i;
	int i2;

	push(min, b->ary[0]);
	push(idx, 0);
	i = 0;
	while (++(i) <= b->top)
	{
		if (peek(min) >= b->ary[i])
		{
			push(min, b->ary[i]);
			push(idx, min->top);
		}
		else
		{
			i2 = min->top;
			while (i2 > 0 && min->ary[i2 - 1] < b->ary[i])
				i2--;
			min->ary[i2] = b->ary[i];
			push(idx, i2);
		}
	}
}

static void	find_LIDS(t_stack *ali, t_stack *idx, int range)
{
	free(ali->ary);
	init_stack(ali);
	while (range >= 0 && idx->top >= 0)
	{
		if (peek(idx) == range)
		{
			push(ali, idx->top);
			range--;
		}
		pop(idx);
	}
}

static void	init_idx(t_stack *idx1, t_stack *idx2, t_stack *b)
{
	init_stack(idx1);
	init_stack(idx2);
	idx1->ary[0] = b->top;
	idx1->ary[1] = idx1->ary[0];
	idx1->ary[2] = idx1->ary[0];
}