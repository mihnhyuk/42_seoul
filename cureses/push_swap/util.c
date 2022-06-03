/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:42:23 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/03 18:18:23 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

t_list	*new_node(void)
{
	t_list		*n;
	static int	idx;

	n = (t_list *)malloc(sizeof(t_list));
	n->next = 0;
	n->idx = idx;
	idx++;
	return (n);
}

void	print_stack(t_stack *a, t_stack *b)
{
	int	height;
	int	atop;
	int	btop;

	if (a->top > b->top)
		height = a->top;
	else
		height = b->top;
	atop = a->top;
	btop = b->top;
	while (height >= 0)
	{
		if (atop == height)
			ft_putnbr_fd(a->ary[atop--], 1);
		else
			write(1, ".", 1);
		write (1, "  ", 2);
		if (btop == height)
			ft_putnbr_fd(b->ary[btop--], 1);
		else
			write(1, ".", 1);
		write(1, "\n", 1);
		height--;
	}
}

void	init_result(t_result *result, char *result_map[])
{
	result->top = -1;
	result->capacity = 100;
	result->used_inst = (int *)malloc(100 * sizeof(int));
	result_map[1] = "sa";
	result_map[2] = "sb";
	result_map[3] = "ss";
	result_map[4] = "pa";
	result_map[5] = "pb";
	result_map[6] = "ra";
	result_map[7] = "rb";
	result_map[8] = "rr";
	result_map[9] = "rra";
	result_map[10] = "rrb";
	result_map[11] = "rrr";
}

void	push_result(t_result *result, int data)
{
	int	*tmp;
	int	idx;

	idx = 0;
	if (result->top + 1 >= result->capacity)
	{
		tmp = (int *)malloc(result->capacity * 2 * sizeof(int));
		if (tmp == NULL)
			return ;
		result->capacity *= 2;
		while (idx <= result->top)
		{
			tmp[idx] = result->used_inst[idx];
			idx++;
		}
		free(result->used_inst);
		result->used_inst = tmp;
	}
	result->used_inst[++(result->top)] = data;
}
