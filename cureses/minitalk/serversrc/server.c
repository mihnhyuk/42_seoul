/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:12:04 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/30 17:51:16 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	init_sigstruct(struct sigaction *sig1, struct sigaction *sig2);

int main()
{
	struct sigaction sig1;
	struct sigaction sig2;

	init_sigstruct(&sig1, &sig2);
	ft_printf("Process ID : %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}

static void	init_sigstruct(struct sigaction *sig1, struct sigaction *sig2)
{
	sig1->sa_handler = 0;
	sig2->sa_handler = 0;
	sig1->sa_flags = SA_SIGINFO;
	sig2->sa_flags = SA_SIGINFO;
	sig1->sa_sigaction = sig_handler1;
	sig2->sa_sigaction = sig_handler2;
	sigaction(SIGUSR1, sig1, 0);
	sigaction(SIGUSR2, sig2, 0);
}