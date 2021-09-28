/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuchoi <kyuchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:37:56 by kyuchoi           #+#    #+#             */
/*   Updated: 2021/09/26 18:31:36 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#define ERROR "Error\n"
#define DICT_ERROR "Dict Error\n"
#define BUFF_SIZE 1024

void	input(char *file_name)
{
	 int	fd;
	char	buff[1024];
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		write(1, "Error\n", 6);
	else
	{
		read(fd, buff, BUFF_SIZE);
		write(1, buff, BUFF_SIZE);
		close(fd);
	}
}
