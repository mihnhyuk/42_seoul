/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:06:39 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/03 20:42:31 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	send_bit(int pid, unsigned char c);
static int	send_null(int pid);

void	send_string_sig(int pid, char *sig)
{
	while (*sig)
	{
		if (send_bit(pid, (unsigned char)*sig) == -1)
			return ;
		sig++;
	}
	send_null(pid);
}

static int	send_bit(int pid, unsigned char c)
{
	int	idx;

	idx = 0;
	while (idx < 8)
	{
		if ((c & 1) == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (error_msg("Send error"));
			usleep(50);
			// pause();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (error_msg("Send error"));
			usleep(50);
			// pause();
		}
		c = (c >> 1);
		idx++;
	}
	return (0);
}

static int	send_null(int pid)
{
	int	idx;

	idx = 0;
	while (idx < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			return (error_msg("Send error"));
		usleep(50);
		idx++;
	}
	return (0);
}
