/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:53:35 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/14 21:23:05 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	idx;
	
	idx = 0;
	while (idx < size)
	{
		dest[idx] = src[idx];
		idx++;
	}
	return (dest);
}
