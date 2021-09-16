/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:32:04 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/16 20:09:39 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
