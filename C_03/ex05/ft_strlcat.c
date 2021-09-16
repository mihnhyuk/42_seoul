/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:13:08 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/16 21:36:04 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	dest_sz;

	idx = 0;
	while (dest[idx])
		idx++;
	dest_sz = idx;
	if (size == 0)
	{
		while (src[idx - dest_sz])
			idx++;
		return (idx);
	}
	while (idx < size - 1 && src[idx - dest_sz])
	{
		dest[idx] = src[idx - dest_sz];
		idx++;
	}
	dest[idx] = '\0';
	while (src[idx - dest_sz])
		idx++;
	return (idx);
}
