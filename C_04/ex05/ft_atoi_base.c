/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:32:22 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/23 18:50:49 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_len(char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
		idx++;
	return (idx);
}

int	check_base(char *base)
{
	int	ascii[260];
	int	idx;
	int	tmp;

	idx = 0;
	while (idx < 260)
	{
		ascii[idx] = 1;
		idx++;
	}
	idx = 0;
	while (base[idx])
	{
		tmp = base[idx];
		if (ascii[tmp])
			ascii[tmp] = 0;
		else
			return (0);
		if (base[idx] == '+' || base[idx] == '-' || base[idx] == ' ')
			return (0);
		idx++;
	}
	return (1);
}

int	check_sign(char *str, int *idx)
{
	int	count_minus;

	count_minus = 1;
	while (str[*idx] == ' ' || str[*idx] == '\f' || str[*idx] == '\n'
		|| str[*idx] == '\r' || str[*idx] == '\t' || str[*idx] == '\v')
	{
		(*idx)++;
	}
	while (str[*idx] == '-' || str[*idx] == '+')
	{
		if (str[*idx] == '-')
			count_minus *= -1;
		(*idx)++;
	}
	return (count_minus);
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

int	ft_atoi_base(char *str, char *base)
{
	int	count_minus;
	int	idx;
	int	to_int;
	int	len;
	int	changed_char;

	len = base_len(base);
	if (len <= 1 || !check_base(base) || *str == '\0')
		return (0);
	idx = 0;
	to_int = 0;
	count_minus = check_sign(str, &idx);
	changed_char = base_change(str[idx], base);
	while (str[idx] && changed_char != -1)
	{
		to_int *= len;
		to_int += changed_char;
		idx++;
		changed_char = base_change(str[idx], base);
	}
	to_int *= count_minus;
	return (to_int);
}
