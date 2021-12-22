/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:09:49 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/16 22:09:50 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		idx;
	int		s1len;
	char	*new_str;

	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	idx = 0;
	while (s1[idx])
	{
		new_str[idx] = s1[idx];
		idx++;
	}
	s1len = idx;
	idx = 0;
	while (s2[idx])
	{
		new_str[idx + s1len] = s2[idx];
		idx++;
	}
	new_str[idx + s1len] = '\0';
	return (new_str);
}
