/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_to_token2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:10:49 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/30 16:38:35 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<stdlib.h>
#include"ft_printf.h"
#include"lib/libft.h"

char	*int_to_token(va_list ap);
char	*unsigned_int_to_token(va_list ap);
char	*hex_to_token(va_list ap);
char	*hex_to_token_upper(va_list ap);

char	*int_to_token(va_list ap)
{
	int				input;
	unsigned int	nb;
	int				idx;
	char			ary[12];

	input = va_arg(ap, int);
	nb = (unsigned int)input;
	idx = ft_int_length(input, 10);
	ary[idx] = '\0';
	if (input < 0)
		nb = (unsigned int)input * (-1);
	while (nb > 9)
	{
		ary[--idx] = (nb % 10) + '0';
		nb /= 10;
	}
	ary[--idx] = nb + '0';
	if (input < 0)
		ary[--idx] = '-';
	return (ft_strdup(ary));
}

char	*unsigned_int_to_token(va_list ap)
{
	unsigned int	input;
	int				idx;
	char			ary[12];

	input = va_arg(ap, int);
	idx = ft_unsigned_int_length(input, 10);
	ary[idx] = '\0';
	while (input > 9)
	{
		ary[--idx] = (input % 10) + '0';
		input /= 10;
	}
	ary[--idx] = input + '0';
	return (ft_strdup(ary));
}

char	*hex_to_token(va_list ap)
{
	unsigned int	input;
	int				idx;
	char			ary[10];
	char			*hex;

	hex = "0123456789abcdef";
	input = va_arg(ap, int);
	idx = ft_unsigned_int_length(input, 16);
	ary[idx] = '\0';
	while (input > 15)
	{
		ary[--idx] = hex[input % 16];
		input /= 16;
	}
	ary[--idx] = hex[input];
	return (ft_strdup(ary));
}

char	*hex_to_token_upper(va_list ap)
{
	unsigned int	input;
	int				idx;
	char			ary[10];
	char			*hex;

	hex = "0123456789ABCDEF";
	input = va_arg(ap, int);
	idx = ft_unsigned_int_length(input, 16);
	ary[idx] = '\0';
	while (input > 15)
	{
		ary[--idx] = hex[input % 16];
		input /= 16;
	}
	ary[--idx] = hex[input];
	return (ft_strdup(ary));
}
