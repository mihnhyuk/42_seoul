/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tofunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:55:57 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/16 19:56:02 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c += 'A' - 'a';
	}
	return (c);
}

int	tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 'a' - 'A';
	}
	return (c);
}

static int	check_blank(const char *str, int idx)
{
	while (str[idx] == ' ' || str[idx] == '\f' || str[idx] == '\n'
		|| str[idx] == '\r' || str[idx] == '\t' || str[idx] == '\v')
	{
		idx++;
	}
	return (idx);
}

static int	check_sign(const char *str, int *idx)
{
	int	count_minus;

	count_minus = 1;
	while (str[*idx] == '-' || str[*idx] == '+')
	{
		if (str[*idx] == '-')
			count_minus *= -1;
		(*idx)++;
	}
	return (count_minus);
}

int	ft_atoi(const char *str)
{
	int	count_minus;
	int	idx;
	int	to_int;

	idx = 0;
	to_int = 0;
	idx = check_blank(str, idx);
	count_minus = check_sign(str, &idx);
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		to_int *= 10;
		to_int += str[idx] - '0' ;
		idx++;
	}
	to_int *= count_minus;
	return (to_int);
}
