/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:06:17 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/22 08:51:54 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
DESCRIPION:
The strdup() function returns a pointer to a new string which is
a duplicate of the string s.  Memory for the new string is
obtained with malloc(3), and can be freed with free(3).

RETURN:
On success, the strdup() function returns a pointer to the
duplicated string.  It returns NULL if insufficient memory was
available, with errno set to indicate the error.
*/

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
