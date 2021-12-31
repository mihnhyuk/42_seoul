/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:07:16 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/29 14:15:13 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	 int	str_iter;
	char	*new_str;

	str_iter = 0;
	while (src[str_iter])
		str_iter++;
	new_str = (char *)malloc((str_iter + 1) * sizeof (char));
	if (new_str == NULL)
	{
		return (0);
	}
	str_iter = 0;
	while (src[str_iter])
	{
		new_str[str_iter] = src[str_iter];
		str_iter++;
	}
	new_str[str_iter] = '\0';
	return (new_str);
}
