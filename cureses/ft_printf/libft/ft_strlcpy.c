/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:55:24 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/29 13:55:25 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	if (size == 0)
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
