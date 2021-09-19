/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:13:08 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/19 20:35:06 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	dest_sz;
	unsigned int	src_sz;

	idx = 0;
	while (dest[idx])
		idx++;
	dest_sz = idx;
	idx = 0;
	while (idx + dest_sz + 1 < size && src[idx])
	{
		dest[idx + dest_sz] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	while (src[idx])
		idx++;
	src_sz = idx;
	return (dest_sz + src_sz);
}
