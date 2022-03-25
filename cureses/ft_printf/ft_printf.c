/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:06:20 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/25 16:54:32 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<stdlib.h>
#include"ft_printf.h"
#include"./src/libft.h"

int		ft_printf(const char *str, ...);
void	write_token(char **token, const char *str, va_list ap);
void	regstr_to_token(char **token, const char *str, int *idx);
void	print_token(char **token);

int	ft_printf(const char *str, ...)
{
	int		token_num;
	char	**token;
	va_list	ap;

	va_start(ap, str);
	token_num = get_token_num(str);
	token = (char **)malloc(token_num * sizeof(char *));
	write_token(token, str, ap);
	print_token(token);
	va_end(ap);
	return (0);
}

void	write_token(char **token, const char *str, va_list ap)
{
	int	idx;
	int	token_idx;

	token_idx = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			var_to_token(&(token[token_idx]), str[idx + 1], ap);
			idx += 2;
		}
		else
			regstr_to_token(&(token[token_idx]), str, &idx);
		token_idx++;
	}
}

void	regstr_to_token(char **token, const char *str, int *idx)
{
	int	start;
	int	i;

	start = *idx;
	while (str[*idx] && str[*idx] != '%')
		(*idx)++;
	*token = (char *)malloc((((*idx) - start + 1) * sizeof(char)));
	i = 0;
	while (start != *idx)
	{
		(*token)[i] = str[start];
		start++;
		i++;
	}
	(*token)[i] = 0;
}

void	print_token(char **token)
{
	while (*token)
	{
		ft_putstr_fd(*token, 1);
		token++;
	}
}
