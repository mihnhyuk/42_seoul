/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:25:50 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/28 12:13:05 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_atoi_base(char *str, char *base);
int		check_base(char *base);
char	*nbr_base(int nb, char *base, char **result);
int		integer_length_base(int nbr, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	 int	input_num;
	 int	result_len;
	char	*result;

	if (!(check_base(base_from) && check_base(base_to)))
		return (NULL);
	input_num = ft_atoi_base(nbr, base_from);
	result_len = integer_length_base(input_num, base_to);
	result = (char *)malloc((result_len + 1) * sizeof (char));
	if (result == NULL)
		return (NULL);
	nbr_base(input_num, base_to, &result);
	return (result);
}

int	check_base(char *base)
{
	int	ascii[260];
	int	idx;
	int	tmp;

	idx = -1;
	while (++idx < 260)
		ascii[idx] = 1;
	if (!*base || !*(base + 1))
		return (0);
	idx = 0;
	while (base[idx])
	{
		tmp = base[idx];
		if (ascii[tmp])
			ascii[tmp] = 0;
		else
			return (0);
		if (base[idx] == '+' || base[idx] == '-' || base[idx] == ' '
			|| base[idx] == '\f' || base[idx] == '\n' || base[idx] == '\r'
			|| base[idx] == '\v' || base[idx] == '\t')
			return (0);
		idx++;
	}
	return (1);
}

int	integer_length_base(int nbr, char *base)
{
	unsigned int	len;
	         int	counter;
	unsigned int	to_p;

	len = 0;
	while (base[len])
		len++;
	counter = 0;
	if (nbr < 0)
	{
		counter++;
		to_p = (unsigned int)nbr * (-1);
	}
	else
		to_p = (unsigned int)nbr;
	while (to_p + 1 > len)
	{
		counter++;
		to_p /= len;
	}
	counter++;
	return (counter);
}
