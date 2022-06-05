/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:41:23 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/04 21:30:29 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_blank(const char c);
static int	check_sign(const char c);
static void	init_var(int *flag);
static int	cond(const char c, int *flag);

int	input_check(int argc, char **argv)
{
	int	idx;
	int	s;
	int	flag[5];

	idx = 0;
	if (argc < 2)
		return (0);
	while (++idx < argc)
	{
		s = -1;
		init_var(flag);
		while (argv[idx][++s])
		{
			if (cond(argv[idx][s], flag))
				return (0);
		}
		if (!flag[2])
			return (0);
	}
	return (1);
}

static int	cond(const char c, int *f)
{
	if (c >= '0' && c <= '9' )
	{
		f[1] = 1;
		f[2] = 1;
		f[0] = 0;
	}
	else if (check_blank(c) && f[1])
	{
		if (f[1])
		{
			f[0] = 1;
			f[1] = 1;
		}
	}
	else if (check_sign(c) && f[0] && f[1])
	{
		f[0] = 0;
		f[1] = 0;
	}
	else
		return (1);
	return (0);
}

static void	init_var(int *flag)
{
	flag[0] = 1;
	flag[1] = 1;
	flag[2] = 0;
	flag[3] = 0;
	flag[4] = 0;
}

static int	check_blank(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	check_sign(const char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}
