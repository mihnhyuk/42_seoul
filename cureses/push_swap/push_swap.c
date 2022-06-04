/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:28:47 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/04 20:32:38 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

static int	init(int argc, char **argv, t_stack *a);
static void	init_values(t_stack *a, t_stack *b,
				t_result *result, char *result_map[]);
static void	print_result(t_result *result, char *result_map[]);
static void	free_all(t_stack *a, t_stack *b, t_result *r);

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_result	result;
	char		*result_map[12];
	
	init_values(&a, &b, &result, result_map);
	if (init(argc, argv, &a))
		return (0);
	if (dup_check(&a))
		return (0);
	sort(&a, &b, &result);
	print_result(&result, result_map);
	//printf("inst: %d", result.top + 1);
	free_all(&a, &b, &result);
	return (0);
}

static int	init(int argc, char **argv, t_stack *a)
{
	int	idx;
	int	tmp;

	if (a->ary == NULL)
		return (1);
	idx = argc - 1;
	tmp = input_check(argc, argv);
	if (tmp == 1)
		one_arg(argv[1], a);
	else if (tmp == 2)
	{
		if (many_args(argv, idx, a))
			return (0);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

static void	init_values(t_stack *a, t_stack *b,
			t_result *result, char *result_map[])
{
	init_stack(a);
	init_stack(b);
	init_result(result, result_map);
}

static void	print_result(t_result *result, char *result_map[])
{
	int	idx;

	idx = 0;
	while (idx < result->top + 1)
	{
		ft_putstr_fd(result_map[result->used_inst[idx]], 1);
		idx++;
		write(1, "\n", 1);
	}
}

static void	free_all(t_stack *a, t_stack *b, t_result *r)
{
	free(a->ary);
	free(b->ary);
	free(r->used_inst);
}
