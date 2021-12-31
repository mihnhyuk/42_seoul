/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:08:21 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/31 15:58:48 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	length;
	unsigned int	idx;
	char			*result;

	length = ft_strlen(s);
	idx = 0;
	result = (char *)malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	while (idx < length)
	{
		result[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	result[idx] = 0;
	return (result);
}
