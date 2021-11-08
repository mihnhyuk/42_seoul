/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:21:19 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/29 19:21:20 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	plus_oper(int a, int b)
{
	ft_putnbr(a + b);
}

void	minus_oper(int a, int b)
{
	ft_putnbr(a - b);
}

void	multi_oper(int a, int b)
{
	ft_putnbr(a * b);
}

void	div_oper(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
}

void	mod_oper(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
}
