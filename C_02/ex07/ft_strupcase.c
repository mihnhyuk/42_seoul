/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:45:37 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/14 19:23:01 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strupcase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
		{
			str[idx] += ('A' - 'a');
		}
		idx++;
	}
	return (str);
}
