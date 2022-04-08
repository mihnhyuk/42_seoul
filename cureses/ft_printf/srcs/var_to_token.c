/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_to_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:52:36 by minhjang          #+#    #+#             */
/*   Updated: 2022/04/01 19:59:12 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
<<<<<<< HEAD:cureses/ft_printf/srcs/var_to_token.c
#include"ft_printf.h"
#include"lib/libft.h"
=======
#include"../includes/ft_printf.h"
#include"../libft/libft.h"
>>>>>>> bcbcbdc7d2c460a80d8d54621763e93e44001a60:cureses/ft_printf/src/var_to_token.c

char	*char_to_token(va_list ap, int *token_num);
char	*str_to_token(va_list ap);
char	*pointer_to_token(va_list ap);

int	v_to_tk(char **token, const char format_char,
			 va_list ap, int *token_num)
{
	if (format_char == 'c')
	{
		*token = char_to_token(ap, token_num);
		if (*token_num == 1)
			return (1);
	}
	else if (format_char == 's')
		*token = str_to_token(ap);
	else if (format_char == 'p')
		*token = pointer_to_token(ap);
	else if (format_char == 'd' || format_char == 'i')
		*token = int_to_token(ap);
	else if (format_char == 'u')
		*token = unsigned_int_to_token(ap);
	else if (format_char == 'x')
		*token = hex_to_token(ap);
	else if (format_char == 'X')
		*token = hex_to_token_upper(ap);
	else if (format_char == '%')
		*token = ft_strdup("%");
	if (*token == NULL)
		return (-1);
	return (ft_strlen(*token));
}

char	*char_to_token(va_list ap, int *token_num)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * 2);
	if (result == NULL)
		return (0);
	result[0] = va_arg(ap, int);
	result[1] = 0;
	*token_num = 1;
	return (result);
}

char	*str_to_token(va_list ap)
{
	char	*result;

	result = va_arg(ap, char *);
	if (result == NULL)
		result = ft_strdup("(null)");
	else
		result = ft_strdup(result);
	if (result == NULL)
		return (NULL);
	return (result);
}

char	*pointer_to_token(va_list ap)
{
	unsigned long long int	p_to_i;
	unsigned long long int	tmp;
	            const char	*hex_list = "0123456789abcdef";
	                  char	hex[19];
	                   int	idx;

	idx = 2;
	p_to_i = (unsigned long long int)va_arg(ap, void *);
	if (p_to_i == 0)
		return (ft_strdup("(nil)"));
	tmp = p_to_i;
	while (tmp > 15)
	{
		idx++;
		tmp /= 16;
	}
	hex[++idx] = '\0';
	while (idx >= 2)
	{
		hex[--idx] = *(hex_list + (p_to_i % 16));
		p_to_i /= 16;
	}
	hex[1] = 'x';
	hex[0] = '0';
	return (ft_strdup(hex));
}
