/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:48:03 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/05 23:25:24 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	swap(t_stack *s)
{
	int	tmp;

	if (s->top < 1)
		return ;
	tmp = s->ary[s->top];
	s->ary[s->top] = s->ary[s->top - 1];
	s->ary[s->top - 1] = tmp;
}

void	push(t_stack *s, int data)
{
	int	*tmp;
	int	idx;

	idx = 0;
	if (s->top + 1 >= s->capacity)
	{
		tmp = (int *)malloc(s->capacity * 2 * sizeof(int));
		if (tmp == NULL)
			return ;
		s->capacity *= 2;
		while (idx <= s->top)
		{
			tmp[idx] = s->ary[idx];
			idx++;
		}
		free(s->ary);
		s->ary = tmp;
	}
	s->ary[++(s->top)] = data;
}

int	pop(t_stack *s)
{
	if (s->top == -1)
		return (0);
	return (s->ary[s->top--]);
}

int	peek(t_stack *s)
{
	if (s->top == -1)
		return (0);
	return (s->ary[s->top]);
}

void	init_stack(t_stack *s)
{
	s->top = -1;
	s->capacity = 2;
	s->ary = (int *)malloc(2 * sizeof(int));
}
