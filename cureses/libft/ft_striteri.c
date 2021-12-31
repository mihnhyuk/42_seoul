/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:40:32 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/31 18:48:40 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	idx;
	unsigned int	length;

	idx = 0;
	length = ft_strlen(s);
	while (idx < length)
	{
		(*f)(idx, &s[idx]);
		idx++;
	}
}
