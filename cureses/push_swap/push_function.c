/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:02:55 by minhjang          #+#    #+#             */
/*   Updated: 2022/04/11 15:30:24 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
}

void    pa(t_stack *a, t_stack *b)
{
    if(b->top != -1)
        push(a, pop(b));
}

void    pb(t_stack *b, t_stack *a)
{
    if(b->top != -1)
        push(a, pop(b));
}

void    rs(t_stack *s)
{   
    int 
    
    if(s->top == -1)
        return ;   
}