/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:32:04 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/16 16:45:33 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	unsigned int	dest_sz;

	idx = 0;
	while (dest[idx])
		idx++;
	dest_sz = idx;
	while (src[idx - dest_sz] && idx - dest_sz < nb)
	{
		dest[idx] = src[idx - dest_sz];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
