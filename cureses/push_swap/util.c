/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:42:23 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/04 16:08:57 by minhjang         ###   ########.fr       */
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
	int btop;

	height = a->top > b->top ? a->top : b->top;
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