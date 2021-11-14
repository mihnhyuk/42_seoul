/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:21:58 by minhjang          #+#    #+#             */
/*   Updated: 2021/11/09 01:21:59 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy
(void *restrict dest, const void *restrict src, unsigned int n)
{
	char	*tmp1;
	char	*tmp2;

	tmp2 = src;
	tmp1 = dest;
	while (n > 0)
	{
		*tmp1 = *tmp2++;
		tmp1++;
		n--;
	}
	return (dest);
}

void	*ft_memset(void *s, int c, unsigned int n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n > 0)
	{
		*tmp++ = c;
		n--;
	}
	return (s);
}

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	char	*tmp;
	char	*tmp2;

	tmp = (char *)dest;
	tmp2 = (char *)src;
	if (dest <= src || dest >= src + n)
		return (ft_memcpy(dest, src, n));
	else
	{
		while (n >= 0)
		{
			*(tmp + n) = *(tmp2 + n);
			n--;
		}
		return (dest);
	}
}

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n >= 0)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		tmp++;
		n--;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	int				i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}
