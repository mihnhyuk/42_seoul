/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:02:20 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/16 22:02:21 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		idx;
	char	*new_str;

	idx = 0;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (idx < len && s[start + idx])
	{
		new_str[idx] = s[start + idx];
		idx++;
	}
	new_str[idx] = NULL;
	return (new_str);
}
