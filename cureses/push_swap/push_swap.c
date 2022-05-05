/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:28:47 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/05 20:20:24 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

static void		init(int argc, char **argv, t_stack *a);
static t_list	*input(void);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;


	init_stack(&a);
	init_stack(&b);
	init(argc, argv, &a);
	print_stack(&a, &b);
	printf("\n\n");
	sort(&a, &b);
	print_stack(&a, &b);
	
}

static void	init(int argc, char **argv, t_stack *a)
{
	int	idx;

	idx = argc - 1;
	while (idx >= 1)
	{
		push(a, ft_atoi(argv[idx]));
		idx--;
	}
}

/*
static void	inst(t_list *ins, t_stack *a, t_stack *b)
{
	while (ins->inst != 0)
	{
		if (ft_strcmp(ins->inst, "sa"))
			swap(a);
		else if (ft_strcmp(ins->inst, "sb"))
			swap(b);
		else if (ft_strcmp(ins->inst, "ss"))
			ss(a, b);
		else if (ft_strcmp(ins->inst, "pa"))
			
	}
}
*/
static t_list	*input()
{
	t_list	*ins;
	t_list	*first;

	ins = new_node();
	first = ins;
	while (1)
	{
		ins->inst = get_next_line(1);
		if(ins->inst != 0)
		{
			ins->next = new_node();
			ins = ins->next;
		}
		else
			break ;
	}
	return (first);
}