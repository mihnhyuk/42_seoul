/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:20:39 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/30 23:47:54 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest,
	const void *src, unsigned int n)
{
	int			idx;
	char		*tmp;
	const char	*tmp2;

	idx = 0;
	tmp = (char *)dest;
	tmp2 = src;
	while (n > 0)
	{
		tmp[idx] = tmp2[idx];
		idx++;
		n--;
	}
	return (dest);
}
