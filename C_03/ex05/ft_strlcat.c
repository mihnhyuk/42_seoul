/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:13:08 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/22 23:20:44 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	dest_sz;
	unsigned int	src_sz;

	dest_sz = strlen(dest);
	if (dest_sz >= size)
		return (size + strlen(src));
	idx = 0;
	while (idx + dest_sz + 1 < size && src[idx])
	{
		dest[idx + dest_sz] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	src_sz = strlen(src);
	return (dest_sz + src_sz);
}
