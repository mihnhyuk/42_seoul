/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:17:19 by minhjang          #+#    #+#             */
/*   Updated: 2022/04/13 13:21:37 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_printf.h"
#include"../libft/libft.h"

int	get_token_num(const char *input_str);
int	check_format(const char c);
int	ft_int_length(int nb, unsigned int base);
int	ft_unsigned_int_length(unsigned int n, unsigned int base);
int	is_new_token(const char *input_str, int idx);

int	get_token_num(const char *input_str)
{
	int	token_num;
	int	idx;
	int	format;

	token_num = 0;
	idx = 0;
	while (input_str[idx])
	{
		if (idx == 0 && input_str[idx] != '%')
			token_num++;
		else if (input_str[idx] == '%')
		{
			format = check_format(input_str[++idx]);
			if (format < 0)
				return (-1);
			token_num ++;
			idx++;
			continue ;
		}
		else if (is_new_token(input_str, idx))
			token_num++;
		idx++;
	}
	return (token_num + 1);
}

int	check_format(const char c)
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
		return (-1);
}

int	ft_int_length(int nb, unsigned int base)
{
	int				length;
	unsigned int	n;

	length = 0;
	n = nb;
	if (nb < 0)
	{
		length++;
		n = nb * (-1);
	}
	while (n + 1 > base)
	{
		length++;
		n /= base;
	}
	length++;
	return (length);
}

int	ft_unsigned_int_length(unsigned int n, unsigned int base)
{
	int	length;

	length = 0;
	while (n > base - 1)
	{
		length++;
		n /= base;
	}
	length++;
	return (length);
}

int	is_new_token(const char *input_str, int idx)
{
	int	n;

	n = 0;
	if (idx > 1 && input_str[idx - 2] == '%')
	{
		if (idx == 2)
			return (1);
		else if ((check_format(input_str[idx - 1]) >= 0))
		{
			idx -= 2;
			while (idx >= 0)
			{
				if (input_str[idx] == '%')
					n++;
				else
					break ;
				idx--;
			}
			return (n % 2);
		}
	}
	return (0);
}
