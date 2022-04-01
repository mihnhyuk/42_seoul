/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:55:47 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/31 14:14:16 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	dest_sz;
	unsigned int	src_sz;

	dest_sz = ft_strlen(dest);
	if (dest_sz >= size)
		return (size + ft_strlen(src));
	idx = 0;
	while (idx + dest_sz + 1 < size && src[idx])
	{
		dest[idx + dest_sz] = src[idx];
		idx++;
	}
	dest[idx + dest_sz] = '\0';
	src_sz = ft_strlen(src);
	return (dest_sz + src_sz);
}
