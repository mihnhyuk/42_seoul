/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:51:08 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/18 11:38:54 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

static int	check_blank(const char c);
static int	to_int(t_stack *a, char *st);

int	many_args(char **argv, int idx, t_stack *a)
{
	while (idx >= 1)
	{
		if (one_arg(argv[idx], a, 0))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		idx--;
	}
	return (0);
}

int	one_arg(char *s, t_stack *a, int flag)
{
	char	st[20];
	int		idx;
	int		s_idx;

	idx = 13;
	flag = 0;
	s_idx = ft_strlen(s);
	st[idx--] = '\0';
	while (--s_idx >= 0 && idx >= 0)
	{
		if (!check_blank(s[s_idx]))
		{
			st[idx--] = s[s_idx];
			flag = 1;
		}
		else if (flag)
		{
			flag = 0;
			if (to_int(a, st + idx + 1))
				return (1);
			push(a, ft_atoi(st + idx + 1));
			idx = 12;
		}
	}
	if (flag && to_int(a, st + idx + 1))
		return (1);
	return (0);
}

static int	to_int(t_stack *a, char *st)
{
	if (ft_strlen(st) >= 12)
		return (1);
	else if (ft_strlen(st) == 11 && *st == '+')
	{
		if (st[1] > '2' || ft_atoi(st) < 0)
			return (1);
		
	}
	else if (ft_strlen(st) == 11 && *st == '-')
	{
		if (st[1] > '2' || ft_atoi(st) > 0)
			return (1);
	}
	else if(ft_strlen(st) == 10 && *st != '+' && *st != '-')
	{
		if (st[0] > '2' || ft_atoi(st) < 0)
			return (1);
	}
	push(a, ft_atoi(st));
	return (0);
}


int	dup_check(t_stack *a)
{
	int	i;
	int	d;

	i = -1;
	while (++i <= a->top)
	{
		d = -1;
		while (++d < i)
		{
			if (a->ary[d] == a->ary[i])
			{
				write(2, "Error\n", 6);
				return (1);
			}
		}
	}
	return (0);
}

static int	check_blank(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
