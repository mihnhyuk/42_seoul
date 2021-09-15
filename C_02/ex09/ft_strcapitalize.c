/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:45:37 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/15 17:17:30 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] += ('A' - 'a');
	while (str[idx])
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
		{
			str[idx] += ('a' - 'A');
		}
		idx++;
	}
	return (str);
}
