/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:23:10 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/30 19:01:29 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int push_back(t_dynamicStr *str, char c)
{
    char    *tmp;
	int		idx;
    
    if (str->length + 1 < str->capacity)
    {
		str->str[(str->length)++] = c;
		str->str[str->length] = 0;
		return (1);
    }
    str->capacity *= 2;
    tmp = (char *)malloc(str->capacity * sizeof(char));
	if (tmp == NULL)
	{
		error_msg("Memory shortage");
		return(0);
	}
	idx = -1;
	while (++idx < str->length)
		tmp[idx] = str->str[idx];
	tmp[idx++] = c;
	tmp[idx] = 0;
	free(str->str);
	str->str = tmp;
	return (1);
}

int  error_msg(char *msg)
{
    ft_printf("%s\n", msg);
    return (0);
}