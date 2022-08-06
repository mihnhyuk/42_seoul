/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:39:45 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/31 13:28:06 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	char	*tmp;
	char	*tmp2;

	tmp = (char *)dest;
	tmp2 = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest < src || dest >= src + n)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (n > 0)
		{
			n--;
			*(tmp + n) = *(tmp2 + n);
		}
		*tmp = *tmp2;
		return (dest);
	}
}
