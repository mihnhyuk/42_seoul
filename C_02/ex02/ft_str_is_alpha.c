/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:45:37 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/14 16:17:53 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!((str[idx] >= 'A' && str[idx] <= 'Z') || (str[idx] >= 'a' && str[idx] <= 'z')))
			return (0);
		idx++;
	}
	return (1);
}
