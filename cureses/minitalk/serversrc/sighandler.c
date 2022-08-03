/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:42:39 by minhjang          #+#    #+#             */
/*   Updated: 2022/08/03 20:41:10 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sig_handler1(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
	{
		if (decoder(0) == -1)
			return ;
		// if (decoder(0) == -1)
		// 	kill(info->si_pid, SIGUSR2);
		// else
		// 	kill(info->si_pid, SIGUSR1);
	}
}

void	sig_handler2(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR2)
	{
		if (decoder(1) == -1)
			return ;
		// if (decoder(1) == -1)
		// 	kill(info->si_pid, SIGUSR2);
		// else
		// 	kill(info->si_pid, SIGUSR1);
	}
}
