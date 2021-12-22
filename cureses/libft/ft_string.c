/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:11:59 by minhjang          #+#    #+#             */
/*   Updated: 2021/11/09 01:12:01 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *str)
{
	int	iter;

	iter = 0;
	while (str[iter])
		iter++;
	return (iter);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	if (size == 0 )
	{
		while (src[idx])
			idx++;
		return (idx);
	}
	while ((idx < size - 1) && src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	while (src[idx])
		idx++;
	return (idx);
}

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
	dest[idx] = '\0';
	src_sz = ft_strlen(src);
	return (dest_sz + src_sz);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while ((s1[idx] && s2[idx]) && idx + 1 < n && s1[idx] == s2[idx])
		idx++;
	return (s1[idx] - s2[idx]);
}
