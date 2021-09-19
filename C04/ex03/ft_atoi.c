/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:19:12 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/19 19:58:46 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	count_minus;
	int	idx;
	int	to_int;
	int flag;

	flag = 0;
	count_minus = 1;
	idx = 0;
	to_int = 0;
	while (str[idx])
	{
		if (str[idx] == '-')
		{
			count_minus *= (-1);
			flag = 1;
		}
		if (str[idx] >= '0' && str[idx] <= '9')
		{
			flag = 2;
			to_int *= 10;
			to_int += (str[idx] - '0');
		}
	}
	return (to_int * count_minus);
}
