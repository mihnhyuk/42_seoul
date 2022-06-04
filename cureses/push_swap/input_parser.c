/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:51:08 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/04 18:51:53 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	check_blank(const char c);

int many_args(char **argv, int idx, t_stack *a)
{
    int tmp;

    while (idx >= 1)
    {
        tmp = ft_atoi(argv[idx]);
        push(a, tmp);
        idx--;
    }
    return (0);
}

void one_arg(char *s, t_stack *a)
{
    char    st[20];
    int     idx;
    int     flag;

    idx = 0;
    flag = 0;
    while (*s)
    {
        if (!check_blank(*s))
        {
            st[idx++] = *s;
            flag = 1;
        }
        else if (flag)
        {
            flag = 0;
            st[idx++] = '\0';
            push(a, ft_atoi(st));
            idx = 0;
        }
        s++;
    }
}

int	dup_check(t_stack *a)
{
	int i;
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

