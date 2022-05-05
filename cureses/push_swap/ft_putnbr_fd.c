/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:52:53 by minhjang          #+#    #+#             */
/*   Updated: 2021/12/31 19:10:15 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_recur(int n, int fd)
{
	char	a;

	a = (n % 10) + '0';
	if (n / 10 == 0)
	{
		write(fd, &a, 1);
		return ;
	}
	else
	{
		write_recur(n / 10, fd);
		write(fd, &a, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;

	u_n = n;
	if (n < 0)
	{
		write (fd, "-", 1);
		u_n = -n;
	}
	write_recur(u_n, fd);
}
