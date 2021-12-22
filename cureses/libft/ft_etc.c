/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:44:40 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/16 21:44:43 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, unsigned int n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}
