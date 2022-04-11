/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:27:23 by minhjang          #+#    #+#             */
/*   Updated: 2022/01/19 21:12:00 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_readword	*add_lst(int fd, t_readword *start)
{
	t_readword	*new_lst;

	new_lst = (t_readword *)malloc(sizeof(t_readword));
	if (new_lst == NULL)
		return (NULL);
	new_lst->next = NULL;
	new_lst->fd = fd;
	new_lst->length = 0;
	new_lst->start = start;
	return (new_lst);
}

int	write_lst(int fd, t_readword **iter, char token[BUFFER_SIZE], int idx)
{
	int	idx2;

	while (++idx < BUFFER_SIZE && token[idx] != '\n' && token[idx])
		(*iter)->buf[idx] = token[idx];
	(*iter)->length = idx;
	if (idx < BUFFER_SIZE && token[idx] == '\n')
	{
		(*iter)->length++;
		(*iter)->buf[idx++] = '\n';
		idx2 = -1;
		while (++idx2 < BUFFER_SIZE)
		{
			if (idx < BUFFER_SIZE)
				token[idx2] = token[idx++];
			else
				token[idx2] = 0;
		}
		return (1);
	}
	(*iter)->next = add_lst(fd, (*iter)->start);
	(*iter) = (*iter)->next;
	if ((*iter) == NULL)
		free_lst((*iter)->start);
	 return (clear(token, idx));
}

char	*lst_to_str(t_readword *lst)
{
	int		len;
	int		idx;
	char	*str;

	if (lst->length == 0)
		return (free_lst(lst->start));
	len = get_strlen(lst, 0);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (lst->next)
	{
		idx = copy_lst(lst, &str, idx);
		lst = lst->next;
	}
	idx = copy_lst(lst, &str, idx);
	free_lst(lst->start);
	str[idx] = 0;
	return (str);
}

int	get_strlen(t_readword *lst, int counter)
{
	counter += lst->length;
	if (lst->next)
		counter = get_strlen(lst->next, counter);
	return (counter);
}

int	copy_lst(t_readword *lst, char **str, int idx)
{
	int	lst_idx;

	lst_idx = 0;
	while (lst_idx < lst->length)
		(*str)[idx++] = lst->buf[lst_idx++];
	return (idx);
}
