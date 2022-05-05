/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:29:21 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/05 22:39:38 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ros(t_stack *s);

void	ra(t_stack *s, t_result *result)
{
	ros(s);
	push_result(result, 6);
}

void	rb(t_stack *s, t_result *result)
{
	ros(s);
	push_result(result, 7);
}

void	rr(t_stack *a, t_stack *b, t_result *result)
{
	ros(a);
	ros(b);
	push_result(result, 8);
}

static void	ros(t_stack *s)
{
	int	tmp;
	int	idx;

	if (s->top <= 0)
		return ;
	idx = s->top;
	tmp = peek(s);
	while (idx > 0)
	{
		s->ary[idx] = s->ary[idx - 1];
		idx--;
	}
	s->ary[0] = tmp;
}
