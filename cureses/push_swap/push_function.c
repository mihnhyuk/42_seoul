/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:48:03 by minhjang          #+#    #+#             */
/*   Updated: 2022/04/08 19:56:14 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *s)
{
    int tmp;
    
    if (s.top < 1)
        return ;
    tmp = s->ary[s->top];
    s->ary[s->top] = s->ary[s->top - 1];
    s->ary[s->top - 1] = tmp;
}

void    push(t_stack s)
{

}