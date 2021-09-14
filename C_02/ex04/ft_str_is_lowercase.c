/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:45:37 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/14 16:20:28 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_lowerase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!(str[idx] >= 'a' && str[idx] <= 'z'))
			return (0);
		idx++;
	}
	return (1);
}
