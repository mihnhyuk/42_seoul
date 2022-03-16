/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:30:03 by minhjang          #+#    #+#             */
/*   Updated: 2022/01/19 21:17:07 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*s;
	int		fd;

	fd = 1;

	{
		s = get_next_line(fd);
		//printf("1. %s", s);
		write(1, s, 3);
		free(s);
		/*
		s = get_next_line(fd);
		printf("2. %s", s);
		free(s);
		s = get_next_line(fd);
		printf("3. %s", s);
		free(s);
		s = get_next_line(fd);
		printf("4. %s", s);
		free(s);
		s = get_next_line(fd);
		printf("5. %s", s);
		free(s);
		*/
	}
	close(fd);

	return (0);
}
