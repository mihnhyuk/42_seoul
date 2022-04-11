/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:27:21 by minhjang          #+#    #+#             */
/*   Updated: 2022/04/11 13:47:53 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		clear(char remain[BUFFER_SIZE], int idx);
void	*free_lst(t_readword *lst);

char	*get_next_line(int fd)
{
	static char	remain[OPEN_MAX][BUFFER_SIZE];
	t_readword	*str_begin;

	if (fd >= OPEN_MAX || fd < 0)
		return (NULL);
	str_begin = add_lst(fd, NULL);
	str_begin->start = str_begin;
	if (remain[fd][0])
	{
		if (write_lst(fd, &str_begin, remain[fd], -1) == 1)
			return (lst_to_str(str_begin->start));
	}
	if (0 >= read(fd, remain[fd], BUFFER_SIZE))
		return (lst_to_str(str_begin->start));
	while (!write_lst(fd, &str_begin, remain[fd], -1))
	{
		if (0 >= read(fd, remain[fd], BUFFER_SIZE))
		{
			clear(remain[fd], 0);
			break ;
		}
	}
	return (lst_to_str(str_begin->start));
}

int	clear(char remain[BUFFER_SIZE], int idx)
{
	int	idx2;
	int	flag;

	idx2 = 0;
	if (idx < BUFFER_SIZE && remain[idx] == 0)
		flag = 2;
	else
		flag = 0;
	while (idx2 < BUFFER_SIZE)
	{
		remain[idx2] = 0;
		idx2++;
	}
	return (flag);
}

void	*free_lst(t_readword *lst)
{
	t_readword	*next;

	while (lst->next)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	free(lst);
	return (NULL);
}
