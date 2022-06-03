/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:51:00 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/03 04:25:45 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static int	pivot_comp(t_stack *a, t_stack *b, t_result *result);
int			search_insert_position(t_stack *a, t_stack *b);
void		insert(t_stack *a, t_stack *b, t_result *r, int position);
void		min_to_top(t_stack *a, t_result *r);

void	sort(t_stack *a, t_stack *b, t_result *result)
{
	t_stack	ali;
	//int t;

	init_stack(&ali);
	if (ali.ary == NULL)
		return ;
	if (is_aligned(a, &ali) == 1)
		return ;
	pivot_comp(a, b, result);
	//print_stack(a, b);
	//printf("\n");
	while (b->top != -1)
	{
		//print_stack(a, b);
		LIDS(b, &ali);
		//printf("%d\n", ali.top);
		//for (int i = 0 ; i < ali.top + 1 ; i++){
		//	printf("%d ", ali.ary[i]);
		//}
		sort_merge(a, b, result, &ali);
		//scanf("%d", &t);
	}
	min_to_top(a, result);
	free(ali.ary);
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

int	search_insert_position(t_stack *a, t_stack *b)
{
	int	idx;
	int	min;
	int	position;

	idx = 0;
	if (a->top == -1)
		return (0);
	min = 0;
	position = a->top;
	while (idx < a->top + 1)
	{
		if (a->ary[idx] < a->ary[min])
			min = idx;
		if (a->ary[idx] > peek(b))
		{
			if (min == idx)
				position = idx;
			else if (position == a->top || position > min)
				position = idx;
		}
		idx++;
	}
	return (position);
}

void	insert(t_stack *a, t_stack *b, t_result *r, int position)
{
	int	idx;
	
	//printf("position: %d peek: %d\n", position, peek(b));
	idx = 0;
	if (position + 1> a->top / 2)
	{
		while (idx++ < a->top - position)
			ra(a, r);
		pa(a, b ,r);
	}
	else
	{
		while (idx++ < position + 1)
			rra(a, r);
		pa(a, b, r);
	}
}

void	min_to_top(t_stack *a, t_result *r)
{
	int	idx;
	int	min;
	int	min_val;

	idx = 0;
	min = 0;
	while (idx++ < a->top)
	{
		if (a->ary[idx] < a->ary[min])
			min = idx;
	}
	min_val = a->ary[min];
	while (peek(a) != min_val)
	{
		if (min > a->top / 2)
			ra(a, r);
		else
			rra(a, r);
	}
}