/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:06:20 by minhjang          #+#    #+#             */
/*   Updated: 2022/03/30 18:01:31 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<stdlib.h>
#include"ft_printf.h"
#include"./libft/libft.h"
#include<unistd.h>

int		ft_printf(const char *str, ...);
int		write_token(char **token, const char *str,
			 va_list ap, int *token_num);
int		regstr_to_token(char **token, const char *str, int *idx);
void	print_token(char **token, int *token_num);
int		free_all(char **token, int err_idx);

int	ft_printf(const char *str, ...)
{
	int		*token_num;
	char	**token;
	int		len;
	va_list	ap;

	va_start(ap, str);
	len = get_token_num(str);
	token = (char **)malloc(len * sizeof(char *));
	token_num = (int *)malloc((len + 1) * sizeof(int *));
	if (token == NULL || token_num == NULL)
		return (-1);
	token_num[0] = len;
	token[token_num[0] - 1] = NULL;
	len = write_token(token, str, ap, token_num);
	if (len == -1)
		return (-1);
	print_token(token, token_num);
	va_end(ap);
	free_all(token, token_num[0] - 2);
	free(token_num);
	return (len);
}

int	write_token(char **token, const char *str, va_list ap, int *tk_n)
{
	int	idx;
	int	t_i;
	int	len;
	int	tk_len;

	len = 0;
	t_i = 0;
	idx = 0;
	while (str[idx])
	{
		if (t_i >= tk_n[0] - 1)
			return (-1);
		if (str[idx] == '%')
		{
			tk_len = v_to_tk(&(token[t_i]), str[idx + 1], ap, &tk_n[t_i + 1]);
			idx += 2;
			t_i++;
		}
		else
			tk_len = regstr_to_token(&(token[t_i++]), str, &idx);
		if (tk_len == -1)
			return (free_all(token, t_i - 1));
		len += tk_len;
	}
	return (len);
}

int	regstr_to_token(char **token, const char *str, int *idx)
{
	int	start;
	int	i;

	start = *idx;
	while (str[*idx] && str[*idx] != '%')
		(*idx)++;
	*token = (char *)malloc((((*idx) - start + 1) * sizeof(char)));
	if (*token == NULL)
		return (0);
	i = 0;
	while (start != *idx)
	{
		(*token)[i] = str[start];
		start++;
		i++;
	}
	(*token)[i] = '\0';
	return (ft_strlen(*token));
}

void	print_token(char **token, int *token_num)
{
	int	idx;

	idx = 0;
	while (token[idx])
	{
		if (token_num[idx + 1] == 1)
			write(1, token[idx], 1);
		else
			ft_putstr_fd(token[idx], 1);
		idx++;
	}
}

int	free_all(char **token, int err_idx)
{
	while (err_idx >= 0)
	{
		free(token[err_idx]);
		err_idx--;
	}
	free(token);
	return (-1);
}
