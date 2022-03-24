/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_to_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:52:36 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/25 04:13:52 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<stdlib.h>
#include"ft_printf.h"
#include"src/libft.h"

#include<unistd.h>

char	*char_to_token(va_list ap);
char	*str_to_token(va_list ap);
char	*pointer_to_token(va_list ap);
char	*int_to_token(va_list ap);
char	*unsigned_int_to_token(va_list ap);
char	*hex_to_token(va_list ap);
char	*HEX_to_token(va_list ap);

char*	var_to_token(char **token, const char format_char, va_list ap)
{
	if (format_char == 'c')
		*token = char_to_token(ap);
	else if (format_char == 's')
		*token = str_to_token(ap);
	else if (format_char == 'p')
		*token = pointer_to_token(ap);
	else if (format_char == 'd' || format_char =='i')
		*token = int_to_token(ap);
	else if (format_char == 'u')
		*token = unsigned_int_to_token(ap);
	else if (format_char == 'x')
		*token = hex_to_token(ap);
	else if (format_char == 'X')
		*token = HEX_to_token(ap);
	else if (format_char == '%')
		*token = ft_strdup("%%");
	else
		*token = NULL;
	return (*token);
}

char	*char_to_token(va_list ap)
{
	char *result;
	result = (char *)malloc(sizeof(char) * 2);
	if (result == NULL)
		return (0);
	result[0] = va_arg(ap, int);
	result[1] = 0;
	return (result);
}

char	*str_to_token(va_list ap)
{
	char	*result;

	result = ft_strdup(va_arg(ap, char*));
	return (result);
}

char	*pointer_to_token(va_list ap)
{
	unsigned long long int	p_to_i;
	            const char	*hex_list = "0123456789abcdef";
	                  char	*hex;
	                   int	idx;

	idx = 0;
	hex = (char *)malloc(19 * sizeof(char));
	while (idx < 16)
		hex[idx++] = 0;
	hex[idx] = '\0';
	p_to_i = (unsigned long long int)va_arg(ap, void *);
	while (idx >= 0)
	{
		hex[--idx] = *(hex_list + (p_to_i % 16));
		p_to_i /= 16;
	}
	hex[--idx] = 'x';
	hex[idx] = '0';
	return (hex);
}

char	*int_to_token(va_list ap)
{
	int				input;
	unsigned int	nb;
	int				idx;
	char			*ary;

	input =  va_arg(ap, int);
	nb = (unsigned int)input;
	idx = ft_int_length(input, 10);
	ary = (char *)malloc(idx * sizeof(char));
	if (ary == NULL)
		return (NULL);
	if (input < 0)
	{
		ary[idx--] = '-';
		nb = (unsigned int)input * (-1);
	}
	while (nb > 9)
	{
		ary[idx--] = (nb % 10) + '0';
		nb /= 10;
	}
	ary[idx] = nb + '0';
	return (ary);
}

char	*unsigned_int_to_token(va_list ap)
{
	unsigned int	input;
	int				idx;
	char			*ary;

	input =  va_arg(ap, int);
	idx = ft_unsigned_int_length(input, 10);
	ary = (char *)malloc(idx * sizeof(char));
	if (ary == NULL)
		return (NULL);
	while (input > 9)
	{
		ary[idx--] = (input % 10) + '0';
		input /= 10;
	}
	ary[idx] = input + '0';
	return (ary);
}

char	*hex_to_token(va_list ap)
{
	unsigned int	input;
	int				idx;
	char			*ary;
	char			*hex;

	hex = "01234566789abcdef";
	input =  va_arg(ap, int);
	idx = ft_unsigned_int_length(input, 16);
	ary = (char *)malloc(idx * sizeof(char));
	if (ary == NULL)
		return (NULL);
	while (input > 16)
	{
		ary[idx--] = hex[input % 16];
		input /= 16;
	}
	ary[idx] = hex[input];
	return (ary);
}

char	*HEX_to_token(va_list ap)
{
	unsigned int	input;
	int				idx;
	char			*ary;
	char			*hex;

	hex = "01234566789ABCDEF";
	input =  va_arg(ap, int);
	idx = ft_unsigned_int_length(input, 16);
	ary = (char *)malloc(idx * sizeof(char));
	if (ary == NULL)
		return (NULL);
	while (input > 16)
	{
		ary[idx--] = hex[input % 16];
		input /= 16;
	}
	ary[idx] = hex[input];
	return (ary);
}
