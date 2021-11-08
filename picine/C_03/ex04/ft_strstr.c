/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:49:39 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/21 07:48:00 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	begin;
	unsigned int	idx;

	begin = 0;
	if (!(*to_find))
		return (str);
	while (str[begin])
	{
		idx = 0;
		while (str[begin + idx] == to_find[idx])
		{
			if (!(to_find[idx + 1]))
				return (str + begin);
			idx++;
		}
		begin++;
	}
	return (str + begin);
}
