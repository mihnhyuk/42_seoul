/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:51:00 by minhjang          #+#    #+#             */
/*   Updated: 2022/05/05 20:24:52 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void    sort_first(t_stack *a, t_stack *b);

void    sort(t_stack *a, t_stack *b)
{
    sort_first(a, b);
}

static void    sort_first(t_stack *a, t_stack *b)
{
    int a_length;
    int max;

    a_length = a->top + 1;
    max = peek(a);
    while (a_length > 0)
    {
        if (max <= peek(a))
            max = peek(a);
        else
        {
            pb(a, b);
            a_length--;
            continue ;
        }
        ra(a);
        a_length--;
    }
}