/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:49:39 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/16 01:11:54 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	begin;
	unsigned int	idx;
	         int	match;
	
	begin = 0;
	while (str[begin])
	{
		idx = 0;
		match = 1;
		while (to_find[idx])
		{
			if (str[begin + idx] != to_find[idx])
			{
				match = 0;
				break;
			}
			idx++;
		}
		if (match)
			return (str + begin);
		begin++;
	}
	return ('\0');
}
