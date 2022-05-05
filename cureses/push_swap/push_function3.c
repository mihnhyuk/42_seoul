/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:43:39 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/05 18:50:33 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rros(t_stack *s);

void    rra(t_stack *s)
{
    rros(s);
}

void    rrb(t_stack *s)
{
    rros(s);
}

void    rrr(t_stack *a, t_stack *b)
{
    rros(a);
    rros(b);
}
static void	rros(t_stack *s)
{
	int	tmp;
	int	idx;

	if (s->top <= 0)
	return ;
	idx = 0;
	tmp = s->ary[0];
	while (idx < s->top)
	{
		s->ary[idx] = s->ary[idx + 1];
		idx++;
		}
	s->ary[s->top] = tmp;
}