/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:32:08 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/27 09:23:53 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strcat(char *dest, char *src)
{
	int	idx;
	int	dest_sz;

	idx = 0;
	while (dest[idx])
		idx++;
	dest_sz = idx;
	while (src[idx - dest_sz])
	{
		dest[idx] = src[idx - dest_sz];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	 int	total_length;
	 int	idx;
	char	*ret_str;

	idx = 0;
	total_length = 0;
	if (size == 0)
		return ((char *)malloc(1));
	while (idx < size)
		total_length += ft_strlen(strs[idx++]);
	total_length += (ft_strlen(sep) * (size - 1));
	ret_str = (char *)malloc((total_length + 1) * sizeof (char));
	if (ret_str == NULL)
		return (NULL);
	ret_str[0] = '\0';
	idx = 0;
	while (idx < size)
	{
		ft_strcat(ret_str, strs[idx]);
		if (idx != size - 1)
			ft_strcat(ret_str, sep);
		idx++;
	}
	return (ret_str);
}
