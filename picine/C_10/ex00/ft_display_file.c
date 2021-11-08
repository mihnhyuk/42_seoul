/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:26:08 by minhjang          #+#    #+#             */
/*   Updated: 2021/09/25 22:05:22 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

#define BUFF_SIZE 1024

int	file_read(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 18);
	}
	return (fd);
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		write(1, &str[idx], 1);
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	    int	fd;
	   char	buff[BUFF_SIZE];
	ssize_t	rd_size;

	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else
		fd = file_read(argv[1]);
	if (fd == -1)
		return (0);
	rd_size = read(fd, buff, BUFF_SIZE - 1);
	while (0 < rd_size)
	{
		buff[rd_size] = '\0';
		ft_putstr(buff);
		rd_size = read(fd, buff, BUFF_SIZE - 1);	
	}
	close(fd);
}
