/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 07:02:21 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/31 18:06:53 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		idx;
	char	*result;

	while (s1)
	{
		if (!check_set(*s1, set))
			break ;
		s1++;
	}
	idx = 0;
	while (s1[idx])
		idx++;
	while (s1[--idx])
	{
		if (!check_set(s1[idx], set))
			break ;
	}
	result = (char *)malloc(sizeof(char) * (idx + 2));
	result[++idx] = '\0';
	while (--idx >= 0)
		result[idx] = s1[idx];
	return (result);
}
