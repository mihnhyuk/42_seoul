/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:07:16 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/27 14:07:17 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#define BUFF_SIZE 1024

void	ft_cat()
{
	    int	fd;
	    int	line_counter;
		int	idx;
	   char	buff[BUFF_SIZE];
	ssize_t	re_size;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	line_counter = 0;
	re_size = read(fd, buff, BUFF_SIZE - 1);
	while (re_size > 0)
	{
		idx = -1;
		while (buff[++idx])
		{
			if (buff[idx] == '\n')
				line_counter++;
		}
		re_size = read(fd, buff, BUFF_SIZE);
	}
	close(fd);
	return (line_counter);
}
