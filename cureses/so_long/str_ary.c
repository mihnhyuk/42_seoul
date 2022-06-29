/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:43:55 by minhjang          #+#    #+#             */
/*   Updated: 2022/06/29 18:23:07 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str_ary.h"
#include "so_long.h"

void	*init_strs(t_strary *strs, int size)
{
	strs->capacity = size;
	strs->size = 0;
	strs->ary = (char **)malloc(sizeof(char *) * strs->capacity);
	strs->width = 0;
	if (strs->ary == NULL)
		free(strs);
	return (strs->ary);
}

void	*push_string(t_strary *strs, char *str)
{
	char	**tmp;
	int		i;
	
	if (strs->size >= strs->capacity)
	{
		strs->capacity *= 2;
		tmp = (char **)malloc(sizeof(char *) *strs->capacity);
		if (tmp == NULL)
			return (free_strs(strs, strs->size));
		i = 0;
		while (i < strs->size)
		{
			tmp[i] = strs->ary[i];
			i++;
		}
		free(strs->ary);
		strs->ary = tmp;
	}
	strs->ary[strs->size] = str;
	(strs->size)++;
	return (strs->ary);
}

t_strary	*copy_strs(t_strary *org)
{
	t_strary	*copy;
	int			idx;
	
	copy = (t_strary *)malloc(sizeof(t_strary));
	if (copy == NULL)
		return (NULL);
	copy->capacity = org->capacity;
	copy->ary = (char **)malloc(copy->capacity * sizeof(char *));
	if (copy->ary == NULL)
		return (free_cont(copy));
	copy->size = org->size;
	copy->width = org->width;
	idx = -1;
	while (++idx < copy->size)
	{
		copy->ary[idx] = ft_strdup(org->ary[idx]);
		if (copy->ary[idx] == NULL)
		{
			free_strs(copy, idx + 1);
			return (free_cont(copy));
		}
 	}
	return (copy);
}

void	*free_strs(t_strary *strs, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		free(strs->ary[idx]);
		idx++;
	}
	return (NULL);
}

void	*free_cont(t_strary *strs)
{
	free (strs);
	return (NULL);
}