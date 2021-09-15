/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:45:37 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/15 17:21:38 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if ((str[idx] >= 'A' && str[idx] <= 'Z'))
		{
		}
		else if ((str[idx] >= 'a' && str[idx] <= 'z'))
		{
		}
		else
			return (0);
		idx++;
	}
	return (1);
}
