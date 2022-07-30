/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhjang <minhjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:42:39 by minhjang          #+#    #+#             */
/*   Updated: 2022/07/30 17:57:00 by minhjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void    sig_handler1(int signum, siginfo_t *info, void *context)
{
    (void)context;
    if (signum == SIGUSR1)
    {
        ft_printf("0");
        kill(info->si_pid, SIGUSR1);
    }
}
void    sig_handler2(int signum, siginfo_t *info, void *context)
{
        (void)info;
    (void)context;
    if (signum == SIGUSR2)
    {
        ft_printf("1");
        kill(info->si_pid, SIGUSR1);
    }
}
