/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:02:55 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/04 16:15:33 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top != -1)
		push(a, pop(b));
}

void	pb(t_stack *b, t_stack *a)
{
	if (b->top != -1)
		push(a, pop(b));
}

void	rs(t_stack *s)
{
	int	tmp;
	int	idx;

	if (s->top <= 0)
		return ;
	idx = s->top -1;
	tmp = s->ary[0];
	while (idx >= 0)
	{
		s->ary[idx] = s->ary[idx + 1];
		idx--;
	}
	s->ary[s->top] = tmp;
}

void	rrs(t_stack *s)
{
	int	tmp;
	int	idx;

	if (s->top <= 0)
		return ;
	idx = s->top -1;
	tmp = peek(s);
	while (idx < s->top)
	{
		s->ary[idx - 1] = s->ary[idx];
		idx++;
	}
	s->ary[0] = tmp;
}