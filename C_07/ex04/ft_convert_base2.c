/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:26:03 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/22 15:03:32 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	reverse_ary_cpy(char *ary, int size, char **result);
int		ft_strlen(char *str);
int		base_change(char c, char *base);
int		ft_atoi_base(char *str, char *base);
void	nbr_base(int nb, char *base, char **result);

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	base_change(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (c == base[idx])
			return (idx);
		idx++;
	}
	return (-1);
}

/*
var[0] == len
var[1] == to_int
var[2] == changed_char
var[3] == count_minus
 */

int	ft_atoi_base(char *str, char *base)
{
	int	var[4];

	var[0] = ft_strlen(base);
	if (var[0] <= 1 || *str == '\0')
		return (0);
	var[1] = 0;
	var[3] = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			var[3] *= -1;
	}
	var[2] = base_change(*str, base);
	while (*str && var[2] != -1)
	{
		var[1] *= var[0];
		var[1] += var[2];
		var[2] = base_change(*(++str), base);
	}
	var[1] *= var[3];
	return (var[1]);
}

void	nbr_base(int nbr, char *base, char **result)
{
	unsigned int	len;
	        char	ary[15];
	         int	idx;
	unsigned int	to_p;

	len = ft_strlen(base);
	if (len <= 1)
		return ;
	if (nbr < 0)
		to_p = (unsigned int)(nbr * (-1));
	else
		to_p = (unsigned int)nbr;
	idx = 0;
	while (to_p + 1 > len)
	{
		ary[idx++] = *(base + (to_p % len));
		to_p /= len;
	}
	ary[idx] = *(base + (to_p % len));
	if (nbr < 0)
		ary[++idx] = '-';
	reverse_ary_cpy(ary, idx + 1, result);
}

void	reverse_ary_cpy(char *ary, int size, char **result)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		(*result)[idx] = ary[size - idx - 1];
		idx++;
	}	
}
