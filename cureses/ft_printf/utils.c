/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:17:19 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/22 17:57:24 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	get_token_num(const char *input_str);
int	check_format(const char);

int	get_token_num(const char *input_str)
{
	int	token_num;
	int idx;
	int	format;

	token_num = 1;
	idx = 0;
	while (input_str[idx])
	{
		if (input_str[idx] == '%')
		{
			format = check_format(input_str[++idx]);
			if (format < 0)
				return (-1);
			else
				token_num += 2;
		}
		idx++;
	}
	return (token_num);
}

int check_format(const char c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	else if (c == '%')
		return (9);
	else
		return(-1);
}
